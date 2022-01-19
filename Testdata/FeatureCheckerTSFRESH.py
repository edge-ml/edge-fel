#import csv
#from numpy import genfromtxt
#my_data = genfromtxt('data_1k.csv', delimiter = ',')

import numpy
my_data = numpy.array([1,2,3,4])

import tsfresh.feature_extraction.feature_calculators as fc

res = fc.abs_energy(my_data)
print("abs_energy: ", res)

res = fc.absolute_maximum(my_data)
print("absolute_maximum: ", res)

res = fc.absolute_sum_of_changes(my_data)
print("absolute_sum_of_changes: ", res)

res = fc.autocorrelation(my_data, 1)
print("autocorrelation: ", res)

res = fc.count_above(my_data, 0)
print("count_above: ", res)

res = fc.count_above_mean(my_data)
print("count_above_mean: ", res)

res = fc.count_below(my_data, 1)
print("count_below: ", res)

res = fc.count_below_mean(my_data)
print("count_below_mean: ", res)

res = fc.first_location_of_maximum(my_data)
print("first_location_of_maximum: ", res)

res = fc.first_location_of_minimum(my_data)
print("first_location_of_minimum: ", res)

res = fc.kurtosis(my_data)
print("kurtosis: ", res)

res = fc.last_location_of_maximum(my_data)
print("last_location_of_maximum: ", res)

res = fc.last_location_of_minimum(my_data)
print("last_location_of_minimum: ", res)

res = fc.maximum(my_data)
print("maximum: ", res)

res = fc.mean(my_data)
print("mean: ", res)

res = fc.mean_abs_change(my_data)
print("mean_abs_change: ", res)

res = fc.mean_change(my_data)
print("mean_change: ", res)

res = fc.mean_n_absolute_max(my_data, 8)
print("mean_n_absolute_max: ", res)

res = fc.median(my_data)
print("median: ", res)

res = fc.minimum(my_data)
print("minimum: ", res)

res = fc.number_crossing_m(my_data, 0)
print("number_crossing_0: ", res)

res = fc.quantile(my_data, 0.5)
print("quantile: ", res)

res = fc.range_count(my_data, -1, 1)
print("range_count: ", res)

res = fc.root_mean_square(my_data)
print("root_mean_square: ", res)

res = fc.skewness(my_data)
print("skewness: ", res)

res = fc.standard_deviation(my_data)
print("standard_deviation: ", res)

res = fc.sum_values(my_data)
print("sum_values: ", res)

res = fc.variance(my_data)
print("variance: ", res)

res = fc.fft(my_data)
print("fft: ", res)





























