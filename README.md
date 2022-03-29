# edge-fel
Feature extraction library by _edge-ml_ focused on efficiency written in C++, compatible to Arduino. Edge-fel extracts up to 43 features from one-dimensional time series data and includes a python benchmarking tool with a build-in runtime predictor.

## Main library
The main library classes can be found in edge-fel/Lib. ExtractionDelegate is the entry point and provides wrapper functions for easier access. It also include a cache-map for calculated features, used for "cascading features". ExtractionHandler has a handler function for every feature and is concerned with proving extraction function with parameters. Extractor offer a extraction function for every feature. Each function is written in a "cascading feature"-style, presented in https://github.com/jamiebullock/LibXtract, allowing for faster runtimes and dynamic feature usages.

| ![ClassDiagram](/Docs/ClassDiagram.png?raw=true "edge-fel Class Diagram") |
|:--:| 
| *Class Diagram of edge-fel* |


### Cascading features
Every extraction function for feature is designed in a way, that it does not calculate other features needed for the feature, but expects them as a parameter. As an example, the extraction function for variance does not calculate mean, but receives as a parameter. Already calculated features are saved in a cache-map and reused, to avoid unnecessary recalculations.   

### Adding custom features
To add new features, an explicit calculation function has to added to the Extractor class. Optimally, the function is designed in "cascading feature"-style. An overview of all current feature dependencies can be found below. Additionally, a handler function in the ExtractionHandler class needs to be added. If the feature should be cached, add a cache write call be the checkAndInsert() function as implemented in handle_mean(). If the feature needs other features, add a cache read as seen in handle_variance(). Finally, add the handler function to the handler map in the ExtractionDelegate class.

| ![FeatureDAG](/Docs/FeatureDAG.png?raw=true "edge-fel feature dependencies") |
|:--:| 
| *Feature dependencies in edge-fel* |


## Benchmarker
The python benchmarking tool can collect runtime information of features and predict their runtimes. Connect an Arduino board first and select between three different user modes. At the same time, upload the Arduino firmware provided in the Arduino folder onto you board, so both the firmware and the python script run at the same time.

### Default mode
In the default mode, you can select a dataset from a csv file, the size of the time series, features and params. The input will be combined into a regex and written to a configured serial port where the board is connected. The firmware receives the input and extracts the requested features. Feature results and runtime information will be written to serial by Arduino and printed onto the console by the python script.

### Collect mode
In the collect mode, select a dataset from a csv file, params and specify the name of the connected Arduino board. For every time series length in {10, 20, ... , 100, 200, ... 2000} an iterative extraction of every feature will be performed. Runtime information will be collected and written to a csv file with the name of the Arduino board.

### Predict mode
Enter features for which a runtime prediction should be performed, datasize, caching activation and the connected board. The name of the connected board has to match the name of a csv with runtime information. The runtimes csv file will be used by the mode to build regression models and estimate the runtime an extraction. Timesave with caching is account for by a recursive depth-first search algorithm.

| ![PredictionAlgo](/Docs/PredictionAlgo.PNG?raw=true "edge-fel runtime prediction algorithm") |
|:--:| 
| *Runtime prediction algorithm in edge-fel benchmarking tool* |


## List of features
The library offers 43 different features. 39 features are statistical, scalar features, the remaining 4 being vectorial representations of input data.

| Feature                                        | Explanation                                                                                                                                        |
|------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------|
| Mean                                           | Sum of all values divided by the amount of values.                                                                                                 |
| Mean absolute deviation                        | Mean of the absolute deviations of all values to the mean.                                                                                         |
| Mean geometric absolute                        | N-th root of product of all absolute values.                                                                                                       |
| Median                                         | Value which separates lower half and upper half of all values.                                                                                     |
| Median absolute changes                        | Median of all absolute changes. Changes are the differences between adjacent values.                                                               |
| Median changes                                 | Median of all changes.                                                                                                                             |
| Median absolute deviation                      | Median of the absolute deviations of the values to the median.                                                                                     |
| Standard deviation                             | Root of mean of squared deviations to mean.                                                                                                        |
| Average deviation                              | Root of mean of absolute deviations to mean.                                                                                                       |
| Variance                                       | Mean of squared deviations to mean.                                                                                                                |
| Absolute energy                                | Sum of squared values.                                                                                                                             |
| Kurtosis                                       | Mean of standardised values to the fourth power. Standardised values are the deviation of the value to the mean divided by the standard deviation. |
| Skewness                                       | Mean of standardised values to the third power.                                                                                                    |
| Zero crossing rate                             | Amount of times where adjacent values cross 0 divided by amount of values                                                                          |
| Maximum                                        | Highest value of all values.                                                                                                                       |
| Absolute maximum                               | Absolute highest value of all values.                                                                                                              |
| Minimum                                        | Smallest value of all values.                                                                                                                      |
| Last location of maximum                       | The index of the last occurrence of the maximum value.                                                                                             |
| Last location of minimum                       | The index of the last occurrence of the minimum value.                                                                                             |
| First location of maximum                      | The index of the first occurrence of the maximum value.                                                                                            |
| First location of minimum                      | The index of the first occurrence of the minimum value.                                                                                            |
| Mean n absolute max                            | Mean of the n largest absolute values.                                                                                                             |
| Mean absolute changes                          | Mean of all absolutes changes.                                                                                                                     |
| Mean changes                                   | Mean of all changes.                                                                                                                               |
| Absolute sum of changes                        | Sum of all absolute changes.                                                                                                                       |
| Change quantiles                               | Applies an aggregation function to the changes of all values that are between given quantiles.                                                     |
| Sum values                                     | Sum of all values.                                                                                                                                 |
| Range count                                    | Sum of all values which are between a given lower and upper bound.                                                                                 |
| Non-zero count                                 | Amount of values that are not zero.                                                                                                                |
| Count above                                    | Amount of values that are greater than a given value.                                                                                              |
| Count above mean                               | Amount of values that are greater than the mean of all values.                                                                                     |
| Count below                                    | Amount of values that are smaller than a given value.                                                                                              |
| Count below mean                               | Amount of values that are smaller than the mean of all values.                                                                                     |
| Root mean square                               | Square root of the mean of squared values.                                                                                                         |
| Quantile                                       | The value which is greater than a given percent of all values.                                                                                     |
| Interquartile range                            | The difference of the upper and the lower quartile.                                                                                                |
| Negative turnings                              | Amount of local minimums.                                                                                                                          |
| Positive turnings                              | Amount of local maximums.                                                                                                                          |
| Autocorrelation                                | Correlation of the time series with a delayed copy of itself.                                                                                      |
| Fast fourier transformation (fft)              | Data transformation into a function of frequency.                                                                                                  |
| Linear predictive coding coefficients (lpc)    | Represents the spectral envelope in compressed form.                                                                                               |
| Linear predictive cepstral coefficients (lpcc) | Cepstral coefficients derived from lpc.                                                                                                            |
| Mel frequency cepstral coefficients (mfcc)     | Compact representation of the power spectrum.                                                                                                      |

