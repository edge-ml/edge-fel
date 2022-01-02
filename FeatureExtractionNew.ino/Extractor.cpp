#include "Extractor.h"
#include <cmath>

using namespace ex;
using namespace std;

//Returns the mean of the values
double Extractor::mean(vector<double>& values) {
	double sum = 0;
	for (auto& value : values) {
		sum += value;
	}

	return sum / values.size();
}

//Returns the mean of absolute deviation of a value from the mean
double Extractor::mean_abs_dev(vector<double>& values, double my_mean) {
	double sum = 0;
	for (auto& value : values) {
		sum += abs(value - my_mean);
	}

	return sum / values.size();
}

//Returns the geometric mean of the (absolute) values
double Extractor::mean_geometric(vector<double> values) {
	for (auto& value : values) {
		value = log(value);
	}
	double log_mean = mean(values);
	return exp(log_mean);

	/*
	double product = 1;
	for (auto& value : values) {
		product *= abs(value);
	}

	return pow(product, (1 / values.size()));
	*/
}

//Returns the median of the values
double Extractor::median(vector<double> values) {
	sort(values.begin(), values.end());
	size_t size = values.size();
	if (size % 2 == 0) {
		int mid = size / 2;
		return (values.at(mid) + values.at(mid + 1)) / 2;
	}

	return values.at(size / 2 + 0.5);
}

//Returns the median of all absolute changes
double Extractor::median_abs_diff(vector<double>& values) {
	vector<double> abs_changes;
	for (size_t i = 0; i < values.size() - 1; i++) {
		double diff = abs(values.at(i) - values.at(i + 1));
		abs_changes.push_back(diff);
	}

	return median(abs_changes);
}

//Returns the median of all changes 
double Extractor::median_diff(vector<double>& values) {
	vector<double> changes;
	for (size_t i = 0; i < values.size() - 1; i++) {
		double diff = values.at(i + 1) - values.at(i);
		changes.push_back(diff);
	}

	return median(changes);
}

//Returns the median of all absolute deviations to the median
double Extractor::median_abs_dev(vector<double>& values, double my_median) {
	vector<double> abs_dev;
	for (auto& value : values) {
		double dev = abs(value - my_median);
		abs_dev.push_back(dev);
	}

	return median(abs_dev);
}

//Returns the standard deviation, which is the square root of the variance
double Extractor::std_dev(vector<double>& values, double my_var) {
	return sqrt(my_var);
}

//Returns the average absolute deviation from mean
double Extractor::avg_dev(vector<double>& values, double my_mean) {
	double abs_dev = 0;
	for (auto& value : values) {
		abs_dev += abs(value - my_mean);
	}

	return abs_dev / values.size();
}

//Returns the average quadratic deviation from mean
double Extractor::var(vector<double>& values, double my_mean) {

	double q_dev = 0;
	for (auto& value : values) {
		q_dev += pow(value - my_mean, 2);
	}

	return q_dev / values.size();
}

//Returns the sum of the squared values
double Extractor::abs_energy(vector<double>& values) {
	double sum = 0;
	for (auto& value : values) {
		sum += pow(value, 2);
	}

	return sum;
}

//Returns the mean of standardised values to the power of 4
double Extractor::kurtosis(vector<double>& values, double mean, double std_dev) {
	double sum = 0;
	for (auto& value : values) {
		sum += pow((value - mean) / std_dev, 4);
	}

	return sum / values.size();
}

//Returns the mean of standardised values to the power of 3
double Extractor::skewness(vector<double>& values, double mean, double std_dev) {
	double sum = 0;
	for (auto& value : values) {
		sum += pow((value - mean) / std_dev, 3);
	}

	return sum / values.size();
}

//Returns the percentile of zero crossings of two consecutive values
double Extractor::zero_cross(vector<double>& values) {
	double crosses = 0;
	for (size_t i = 0; i < values.size() - 1; i++) {
		if (values.at(i) * values.at(i + 1) < 0) {
			crosses++;
		}
	}

	return crosses / (values.size() - 1);
}


