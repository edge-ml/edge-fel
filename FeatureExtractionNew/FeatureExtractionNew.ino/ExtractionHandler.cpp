#include "ExtractionHandler.h"

using namespace ed;
using namespace ex;
using namespace eh;
using namespace std;

Extractor extractor;

//Handler function for mean, caches value
double ExtractionHandler::handle_mean(string feature, vector<double>& values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double value = extractor.mean(values);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for mean_abs_dev
double ExtractionHandler::handle_mean_abs_dev(string feature, vector<double>& values) {
	double mean = handle_mean("mean", values);
	return extractor.mean_abs_dev(values, mean);
}

//Handler function for mean_geometric_abs
double ExtractionHandler::handle_mean_geometric_abs(string feature, vector<double>& values) {
	return extractor.mean_geometric_abs(values);
}

//Handler function for median, caches value
double ExtractionHandler::handle_median(string feature, vector<double>& values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double value = extractor.median(values);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for median_abs_diff
double ExtractionHandler::handle_median_abs_diff(string feature, vector<double>& values) {
	return extractor.median_abs_diff(values);
}

//Handler function for median_diff
double ExtractionHandler::handle_median_diff(string feature, vector<double>& values) {
	return extractor.median_diff(values);
}

//Handler function for median_abs_dev, calls handle_median
double ExtractionHandler::handle_median_abs_dev(string feature, vector<double>& values) {
	double median = handle_median("median", values);
	return extractor.median_abs_dev(values, median);
}

//Handler function for std_dev, calls handle_var, caches value
double ExtractionHandler::handle_std_dev(string feature, vector<double>& values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double var = handle_var("var", values);
	double value = extractor.std_dev(values, var);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for avg_dev, calls handle_mean
double ExtractionHandler::handle_avg_dev(string feature, vector<double>& values) {
	double mean = handle_mean("mean", values);
	return extractor.avg_dev(values, mean);
}

//Handler function for var, calls handle_mean, caches value
double ExtractionHandler::handle_var(string feature, vector<double>& values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double mean = handle_mean("mean", values);
	double value = extractor.var(values, mean);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for abs_energy
double ExtractionHandler::handle_abs_energy(string feature, vector<double>& values) {
	return extractor.abs_energy(values);
}

//Handler function for kurtosis, calls handle_mean and handle_std_dev
double ExtractionHandler::handle_kurtosis(string feature, vector<double>& values) {
	double mean = handle_mean("mean", values);
	double std_dev = handle_std_dev("std_dev", values);
	return extractor.kurtosis(values, mean, std_dev);
}

//Handler function for skewness, calls handle_mean and handle_std_dev
double ExtractionHandler::handle_skewness(string feature, vector<double>& values) {
	double mean = handle_mean("mean", values);
	double std_dev = handle_std_dev("std_dev", values);
	return extractor.skewness(values, mean, std_dev);
}

//Handler function for zero_cross
double ExtractionHandler::handle_zero_cross(string feature, vector<double>& values) {
	return extractor.zero_cross(values);
}

//Handler function for max, caches value
double ExtractionHandler::handle_max(string feature, vector<double>& values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double value = extractor.max(values);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for abs_max
double ExtractionHandler::handle_abs_max(string feature, vector<double>& values) {
	return extractor.abs_max(values);
}

//Handler function for min, caches value
double ExtractionHandler::handle_min(string feature, vector<double>& values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double value = extractor.min(values);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for last location of maximum, calls handle_max
double ExtractionHandler::handle_last_location_of_max(string feature, vector<double>& values) {
	double max = handle_max("max", values);
	return extractor.last_location_of_max(values, max);
}

//Handler function for last location of minimum, calls handle_min
double ExtractionHandler::handle_last_location_of_min(string feature, vector<double>& values) {
	double min = handle_min("min", values);
	return extractor.last_location_of_min(values, min);
}

//Handler function for first location of maximum, calls handle_max
double ExtractionHandler::handle_first_location_of_max(string feature, vector<double>& values) {
	double max = handle_max("max", values);
	return extractor.first_location_of_max(values, max);
}

//Handler function for first location of minimum, calls handle_min
double ExtractionHandler::handle_first_location_of_min(string feature, vector<double>& values) {
	double min = handle_min("min", values);
	return extractor.first_location_of_min(values, min);
}

//Handler function for mean_n_abs_max, takes n as input
double ExtractionHandler::handle_mean_n_abs_max(string feature, vector<double>& values, double n) {
	return extractor.mean_n_abs_max(values, n);
}

//Handler function for mean_abs_change
double ExtractionHandler::handle_mean_abs_change(string feature, vector<double>& values) {
	return extractor.mean_abs_change(values);
}

//Handler function for mean_change
double ExtractionHandler::handle_mean_change(string feature, vector<double>& values) {
	return extractor.mean_change(values);
}

//Handler function for abs_sum_of_changes
double ExtractionHandler::handle_abs_sum_of_changes(string feature, vector<double>& values) {
	return extractor.abs_sum_of_changes(values);
}


//Handler function for change_quantiles, takes lower and upper quantile and a aggregation function as input
double ExtractionHandler::handle_change_quantile(string feature, vector<double>& values, double lower, double upper, string aggr) {
	return extractor.change_quantile(values, lower, upper, aggr);
}

//Handler function for sum, caches value
double ExtractionHandler::handle_sum(string feature, vector<double>& values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double value = extractor.sum(values);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for range_count, takes lower and upper bound for values as input
double ExtractionHandler::handle_range_count(string feature, vector<double>& values, double lower, double upper) {
	return extractor.range_count(values, lower, upper);
}

//Handler function for non_zero_count
double ExtractionHandler::handle_non_zero_count(string feature, vector<double>& values) {
	return extractor.non_zero_count(values);
}

//Handler function for count_above, takes lower bound x as input
double ExtractionHandler::handle_count_above(string feature, vector<double>& values, double x) {
	return extractor.count_above(values, x);
}

//Handler function for count_above_mean, calls handle_mean
double ExtractionHandler::handle_count_above_mean(string feature, vector<double>& values) {
	double mean = handle_mean("mean", values);
	return extractor.count_above(values, mean);
}

//Handler function for count_below, takes upper bound x as input
double ExtractionHandler::handle_count_below(string feature, vector<double>& values, double x) {
	return extractor.count_below(values, x);
}

//Handler function for count_below_mean, calls handle_mean
double ExtractionHandler::handle_count_below_mean(string feature, vector<double>& values) {
	double mean = handle_mean("mean", values);
	return extractor.count_below_mean(values, mean);
}

//Handler function for root_mean_square
double ExtractionHandler::handle_root_mean_square(string feature, vector<double>& values) {
	return extractor.root_mean_square(values);
}

//Handler function for quantiles, takes the quantile 0 <= q <= 1 as parameter
double ExtractionHandler::handle_quantile(string feature, vector<double>& values, double q) {
	return extractor.quantile(values, q);
}

//Handler function for interquartile_range
double ExtractionHandler::handle_interquartile_range(string feature, vector<double>& values) {
	return extractor.interquartile_range(values);
}

//Handler function for negative_turnings
double ExtractionHandler::handle_negative_turnings(string feature, vector<double>& values) {
	return extractor.negative_turnings(values);
}

//Handler function for positive_turnings
double ExtractionHandler::handle_positive_turnings(string feature, vector<double>& values) {
	return extractor.positive_turnings(values);
}

//Handler function for autocorrelation, takes the lag as input and calls handle_mean and handle_var
double ExtractionHandler::handle_autocorrelation(string feature, vector<double>& values, double lag) {
	double mean = handle_mean("mean", values);
	double var = handle_var("var", values);
	return extractor.autocorrelation(values, lag, mean, var);
}


//Handler function for mfcc, takes samplingRate, numFilters and the coefficient number as parameter, calls handle_fft and transform result to real numbers
double ExtractionHandler::handle_mfcc(string feature, vector<double>& values, double sampling_rate, double num_filter, double m) {
	vector<Extractor::cd> spectralData = handle_fft("fft", values);
	vector<double> spectralDataReal;
	spectralDataReal.reserve(spectralData.size());
	for (Extractor::cd& c : spectralData) {
		double realValue = sqrt(pow(c.imag(), 2) + pow(c.real(), 2));
		spectralDataReal.push_back(realValue);
	}
	return extractor.mfcc(spectralDataReal, sampling_rate, num_filter, m);
}


//Handler function for fft, transforms vector into imaginary numbers and returns a vector of imaginary doubles
vector<Extractor::cd> ExtractionHandler::handle_fft(string feature, vector<double>& values) {
	vector<Extractor::cd> values_imag;
	values_imag.reserve(values.size());
	for (double value : values) {
		Extractor::cd imag(value, 0.0);
		values_imag.push_back(imag);
	}

	return extractor.fft(values_imag);
}

//Handler function for lpc, creates a vector of n autocorrelations, takes amount of autocorrelations n as param
vector<double> ExtractionHandler::handle_lpc(string feature, vector<double>& values, double auto_n, double lpc_n) {
	int m = auto_n;
	vector<double> autoc;
	autoc.reserve(auto_n);

	while (m--)
	{
		double corr = 0;
		for (int i = 0; i < auto_n - m; i++)
		{
			corr += values[i] * values[i + m];
		}
		autoc.insert(autoc.begin(), corr/ auto_n);
	}
	
	return extractor.lpc(autoc, lpc_n);
}


//Handler function for lpcc, calls lcp, takes length of cepstrum as additional param
vector<double> ExtractionHandler::handle_lpcc(string feature, vector<double>& values, double auto_n, double lpc_n, double cep_length) {
	vector<double> lpc_coeffs = handle_lpc("lpc", values, auto_n, lpc_n);
	return extractor.lpcc(lpc_coeffs, cep_length);
}
