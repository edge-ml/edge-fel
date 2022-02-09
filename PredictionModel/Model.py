import matplotlib.pyplot as plt
import numpy
import pandas
from scipy import stats
from sklearn.linear_model import LinearRegression


def build_and_predict(f):
    runtimes = data[f]
    regress = LinearRegression().fit(data_size, runtimes)
    return regress.predict(numpy.array([my_size]).reshape(-1, 1))


running = True
while running:
    n = int(input("Enter number of features: "))
    features = list(input("Enter features: ").strip().split())[:n]
    my_size = int(input("Enter data size: "))
    print("Predicting runtime for requested size", my_size, "and features:", features)

    data = pandas.read_csv("runtimes_nicla.csv")
    data_size = numpy.array(data['size']).reshape(-1, 1)

    estimated = 0
    for feature in features:
        estimated += build_and_predict(feature)
    print("Feature extraction will take about", estimated, "µs.")
