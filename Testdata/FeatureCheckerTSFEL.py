#import csv
#from numpy import genfromtxt
#my_data = genfromtxt('data_1k.csv', delimiter = ',')

import numpy
my_data = numpy.array([1, 2, 2.5, -1, -2, 3.5, 0, -4, -1, 2])

import tsfel.feature_extraction.features as fc
res = fc.abs_energy(my_data)
print("abs_energy: ", res)

res = fc.autocorr(my_data)
print("autocorr: ", res)

res = fc.calc_max(my_data)
print("max: ", res)

res = fc.calc_mean(my_data)
print("mean: ", res)

res = fc.calc_median(my_data)
print("median: ", res)

res = fc.calc_min(my_data)
print("min: ", res)

res = fc.calc_std(my_data)
print("std: ", res)

res = fc.calc_var(my_data)
print("var: ", res)

res = fc.interq_range(my_data)
print("interq_range: ", res)

res = fc.kurtosis(my_data)
print("kurtosis: ", res)

res = fc.mean_abs_deviation(my_data)
print("mean_abs_deviation: ", res)

res = fc.mean_abs_diff(my_data)
print("mean_abs_diff: ", res)

res = fc.mean_diff(my_data)
print("mean_diff: ", res)

res = fc.median_abs_deviation(my_data)
print("median_abs_deviation: ", res)

res = fc.median_abs_diff(my_data)
print("median_abs_diff: ", res)

res = fc.median_diff(my_data)
print("median_diff: ", res)

res = fc.negative_turning(my_data)
print("negative_turning: ", res)

res = fc.positive_turning(my_data)
print("positive_turning: ", res)

res = fc.rms(my_data)
print("root_mean_square: ", res)


res = fc.skewness(my_data)
print("skewness: ", res)

res = fc.sum_abs_diff(my_data)
print("sum_abs_diff: ", res)

res = fc.zero_cross(my_data)
print("zero_cross: ", res)




























