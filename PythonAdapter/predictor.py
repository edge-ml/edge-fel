import numpy
import pandas
import networkx as nx

from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures


def resolve_cached(feature, data, data_size, my_size):
    parents = list(graph.predecessors(feature))
    parent_time = 0
    for p in parents:
        if p == "root":
            return parent_time
        elif graph.nodes[p]["cached"] == "true":
            parent_time += read_cache_time - build_and_predict(p, data, data_size, my_size)
        else:
            parent_time += write_cache_time + resolve_cached(p, data, data_size, my_size)
            graph.nodes[p]["cached"] = "true"
    return parent_time


def build_and_predict(f, data, data_size, my_size):
    runtimes = data[f]
    lin = LinearRegression().fit(data_size, runtimes)
    lin_score = lin.score(data_size, runtimes)

    poly_features = PolynomialFeatures(degree=2).fit_transform(data_size)
    poly = LinearRegression().fit(poly_features, runtimes)
    poly_score = poly.score(poly_features, runtimes)
    # print(f + " LinR: " + str(lin_score) + ", PolyR:" + str(poly_score))
    if lin_score > poly_score:
        return int(lin.predict(numpy.array([my_size]).reshape(-1, 1)))
    else:
        return int(lin.predict(numpy.array([my_size]).reshape(-1, 1)))


all_features = ["size", "abs_energy", "abs_max", "abs_sum_of_changes", "avg_dev", "count_above_mean",
                "count_below_mean", "first_location_of_max", "first_location_of_min", "interquartile_range", "kurtosis",
                "last_location_of_max", "last_location_of_min", "max", "mean", "mean_abs_changes", "mean_abs_dev",
                "mean_changes", "mean_geometric_abs", "median", "median_abs_dev", "median_abs_changes", "median_changes",
                "min", "negative_turnings", "non_zero_count", "positive_turnings", "root_mean_square", "skewness",
                "std_dev", "sum", "var", "zero_cross", "mean_n_abs_max", "change_quantile", "range_count",
                "count_above", "count_below", "quantile", "autocorrelation"]
write_cache_time = 45
read_cache_time = 55

graph = nx.DiGraph()
graph.add_edges_from(
    [("root", "mean"), ("mean", "var"), ("var", "std_dev"), ("std_dev", "kurtosis"), ("mean", "kurtosis"),
     ("mean", "skewness"), ("std_dev", "skewness"), ("mean", "autocorrelation"), ("var", "autocorrelation"),
     ("root", "lpc"), ("lpc", "lpcc"), ("root", "fft"), ("fft", "mfcc"), ("root", "abs_energy"),
     ("abs_energy", "root_mean_square"), ("root", "median"), ("median", "median_abs_dev"),
     ("max", "first_location_of_max"), ("root", "max"), ("max", "last_location_of_max"), ("root", "min"),
     ("min", "first_location_of_min"), ("min", "last_location_of_min")])


def run():
    features = input("Enter features: ").split()
    if features == ["all"]:
        features = all_features
    my_size = int(input("Enter data size: "))
    do_cache = bool(str(input("Cache? (y/enter): ")))
    platform = input("Enter board: ")
    path = "runtime_results/runtimes_" + platform + ".csv"
    data = pandas.read_csv(path)
    data_size = numpy.array(data['size']).reshape(-1, 1)
    nx.set_node_attributes(graph, "false", name="cached")

    estimated = 0
    for feature in features:
        if not graph.has_node(feature) or not do_cache:
            estimated += build_and_predict(feature, data, data_size, my_size)
        elif graph.nodes[feature]["cached"] == "true":
            estimated += read_cache_time
        else:
            estimated += build_and_predict(feature, data, data_size, my_size) + resolve_cached(feature, data, data_size, my_size)
            if len(list(graph.successors(feature))) > 0:
                estimated += write_cache_time
                graph.nodes[feature]["cached"] = "true"
    print("Feature extraction will take about", estimated, "µs.\n")
