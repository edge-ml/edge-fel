# edge-fel
Feature extraction library by _edge-ml_ focused on efficiency written in C++, compatible to Arduino. Edge-fel extracts up to 43 features from one-dimensional time series data and includes a python benchmarking tool with a build-in runtime predictor.

## Main library
The main library classes can be found in edge-fel/Lib. The ExtractionDelegate is the entry point and provides wrapper functions for easier access. It also include a cache-map for calculated features, used for "cascading features".

## Cascading features

## Benchmarker

## List of features
The library offers 43 different features. 39 features are statistical, scalar features, the remaining 4 being vectorial representations of input data.

| Acronym   | Signature                      | Description                                                                              | Status  |
| :-------- | :----------------------------- | :--------------------------------------------------------------------------------------- | :-----  |
|  'AEN'    | `absolute_energy(x)`           | Returns the absolute energy of the time series which is the sum over the squared values. | ❌     |
|  'AMX'    | `absolute_max(x)`              | Calculates the highest absolute value of the time series x.                              | ❌     |
|  'ASC'    | `absolute_sum_of_changes(x)`   | Returns the sum over the absolute value of consecutive changes in the series x.          | ❌     |
|  'CAM'    | `count_above_mean(x)`          | Returns the number of values in x that are higher than the mean of x.                    | ❌     |
|  'CBM'    | `count_below_mean(x)`          | Returns the number of values in x that are lower than the mean of x.                     | ❌     |
|  'HDV'    | `has_duplicate_values(x)`      | Checks if any value in x occurs more than once.                                          | ❌     |
|  'HMA'    | `has_duplicate_maxima(x)`      | Checks if the maximum value of x is observed more than once.                             | ❌     |
|  'HMI'    | `has_duplicate_minima(x)`      | Checks if the minimum value of x is observed more than once.                             | ❌     |
|  'MEA'    | `mean(x)`                      | Returns the mean of x.                                                                   | ❌     |
|  'MAX'    | `maximum(x)`                   | Calculates the highest value of the time series x.                                       | ❌     |
|  'MIN'    | `minimum(x)`                   | Calculates the lowest value of the time series x.                                        | ❌     |
|  'FMA'    | `first_location_of_maximum(x)` | Returns the first location of the maximum value of x.                                    | ❌     |
|  'FMI'    | `first_location_of_minimum(x)` | Returns the first location of the minimum value of x.                                    | ❌     |
|  'LMA'    | `last_location_of_maximum(x)`  | Returns the last location of the maximum value of x.                                     | ❌     |
|  'LMI'    | `last_location_of_minimum(x)`  | Returns the last location of the minimum value of x.                                     | ❌     |
|  'SUV'    | `sum_values(x)`                | Calculates the sum over the time series x values.                                        | ❌     |
|  'VAR'    | `variance(x)  `                | Returns the variance of x.                                                               | ❌     |
