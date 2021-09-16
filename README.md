# feature-extraction
Feature extraction library by _edge-ml_ focused on efficiency written in C++ for Arduino.

### Questions:
- we want to avoid loading useless methods onto arduino if we do not need them (but is it really worth it? how much can we save?)
- we want to have control over the feature extraction library that we are using in the backend stack. are there existing options that make more sense to reuse?
- what broader benefit could we generate aside from edge-ml with this library?
- what about backward compatability to tsfresh? can we port another framework maybe?
- how to setup the project? Which framework do we use for testing?

## List of features
Just some basic random stuff for now.

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
