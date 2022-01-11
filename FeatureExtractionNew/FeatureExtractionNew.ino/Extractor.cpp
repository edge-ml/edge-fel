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

//Returns the maximum of all values
double Extractor::max(vector<double>& values) {
	double max = values.at(0);
	for (auto& value : values) {
		if (value > max) {
			max = value;
		}
	}
	return max;
}

//Returns the absolute maximum of all values
double Extractor::abs_max(vector<double>& values) {
	double max = abs(values.at(0));
	for (auto& value : values) {
		if (abs(value > max)) {
			max = abs(value);
		}
	}
	return max;
}

//Returns the minimum of all values
double Extractor::min(vector<double>& values) {
	double min = values.at(0);
	for (auto& value : values) {
		if (value < min) {
			min = value;
		}
	}
	return min;
}

//Returns the last location of the maximum value
double Extractor::last_location_of_max(vector<double>& values, double max) {
	size_t index = values.size() - 1;
	for (int i = values.size() - 2; i >= 0; i--) {
		if (values.at(i) == max) {
			index = i;
		}
	}
	return index;
}

//Returns the last location of the minimum value
double Extractor::last_location_of_min(vector<double>& values, double min) {
	size_t index = values.size() - 1;
	for (int i = values.size() - 2; i >= 0; i--) {
		if (values.at(i) == min) {
			index = i;
		}
	}
	return index;
}

//Returns the first location of the maximum value
double Extractor::first_location_of_max(vector<double>& values, double max) {
	size_t index = 0;
	for (int i = 1; i < values.size(); i++) {
		if (values.at(i) == max) {
			return index;
		}
	}
	return index;
}

//Returns the first location of the minimum value
double Extractor::first_location_of_min(vector<double>& values, double min) {
	size_t index = 0;
	for (int i = 1; i < values.size(); i++) {
		if (values.at(i) == min) {
			return index;
		}
	}
	return index;
}

//Returns the average of the n largest values
double Extractor::mean_n_abs_max_values(vector<double> values, int n) {
	sort(values.begin(), values.end());
	double sum = 0;
	for (int i = values.size() - 1; i > values.size() - 1 - n; i--) {
		sum += values.at(i);
	}
	return sum / n;
}


//Returns the mean of the absolute differences of consecutive values
double Extractor::mean_abs_change(vector<double>& values) {
	vector<double> abs_changes;
	for (size_t i = 0; i < values.size() - 1; i++) {
		double diff = abs(values.at(i) - values.at(i + 1));
		abs_changes.push_back(diff);
	}

	return mean(abs_changes);
}

//Returns the mean of differences of consecutive values
double Extractor::mean_change(vector<double>& values) {
	vector<double> changes;
	for (size_t i = 0; i < values.size() - 1; i++) {
		double diff = abs(values.at(i) - values.at(i + 1));
		changes.push_back(diff);
	}

	return mean(changes);
}

//Returns the sum of the absolute differences of consecutive values
double Extractor::abs_sum_of_changes(vector<double>& values) {
	vector<double> abs_changes;
	for (size_t i = 0; i < values.size() - 1; i++) {
		double diff = abs(values.at(i) - values.at(i + 1));
		abs_changes.push_back(diff);
	}

	return sum(abs_changes);
}

//Calculates the absolute differences of all values between the two quantiles and applies the aggregation function
double Extractor::change_quantile(vector<double> values, double lower, double upper, string aggr) {
	sort(values.begin(), values.end());
	vector<double> abs_changes_sub;
	for (size_t i = lower; i <= upper; i++) {
		double diff = abs(values.at(i) - values.at(i + 1));
		abs_changes_sub.push_back(diff);
	}

	if (aggr == "mean") {
		return mean(abs_changes_sub);
	}
	else if (aggr == "median") {
		return median(abs_changes_sub);
	}
	else if (aggr == "var") {
		return var(abs_changes_sub, mean(abs_changes_sub));
	}
	else if (aggr == "std_dev") {
		return std_dev(abs_changes_sub, var(abs_changes_sub, mean(abs_changes_sub)));
	}
	else {
		return 0;
	}
}

//Calculates the sum of all values
double Extractor::sum(vector<double>& values) {
	double sum = 0;
	for (auto value : values) {
		sum += value;
	}
	return sum;
}

//Calculates the sum of all values with a value between lower and upper
double Extractor::range_count(vector<double>& values, double lower, double upper) {
	double sum = 0;
	for (auto value : values) {
		if (value > lower && value < upper) {
			sum += value;
		}
	}
	return sum;
}

//Returns the number of non-zero values
double Extractor::non_zero_count(vector<double>& values) {
	double amount = 0;
	for (auto value : values) {
		if (value != 0) {
			amount++;
		}
	}
	return amount;
}

//Returns the percentage of values greater than x
double Extractor::count_above(vector<double>& values, double x) {
	double amount = 0;
	for (auto value : values) {
		if (value > x) {
			amount++;
		}
	}
	return amount / values.size();
}

//Returns the percentage of values greater than mean
double Extractor::count_above_mean(vector<double>& values, double mean) {
	return count_above(values, mean);
}

//Returns the percentage of values lower than x
double Extractor::count_below(vector<double>& values, double x) {
	double amount = 0;
	for (auto value : values) {
		if (value < x) {
			amount++;
		}
	}
	return amount / values.size();
}

//Returns the percentage of values lower than mean
double Extractor::count_below_mean(vector<double>& values, double mean) {
	return count_below(values, mean);
}

//Returns the root of the mean of all squares values
double Extractor::root_mean_square(vector<double>& values) {
	return sqrt(abs_energy(values)/values.size());
}

//Returns the value which is greater than q*n percent of all values
double Extractor::quantile(vector<double> values, double q) {
	sort(values.begin(), values.end());
	double nq = q * values.size();
	int i = floor(nq);
	if (abs(nq - i) > 0.0001) {
		i= ceil(nq);
		return values.at(i);
	}
	else {
		return (values.at(i) + values.at(i + 1)) / 2;
	}
}

//Returns the difference of the 3/4 and 1/4 quantiles
double Extractor::interquartile_range(vector<double>& values) {
	return quantile(values, 0.75) - quantile(values, 0.25);
}

//Calculates the amount of local minimums
double Extractor::negative_turnings(vector<double>& values) {
	double amount = 0;
	for (int i = 0; i < values.size() - 2; i++) {
		if (values.at(i) > values.at(i + 1) && values.at(i + 1) < values.at(i + 2)) {
			amount++;
		}
	}
	return amount;
}

//Calculates the amount of local maximas
double Extractor::positive_turnings(vector<double>& values) {
	double amount = 0;
	for (int i = 0; i < values.size() - 2; i++) {
		if (values.at(i) < values.at(i + 1) && values.at(i + 1) > values.at(i + 2)) {
			amount++;
		}
	}
	return amount;
}

//Calculates the autocorrelation for a specified lag
double Extractor::autocorrelation(vector<double>& values, int lag, double mean, double var) {
	double sum = 0;
	for (size_t i = 0; i < values.size() - lag; i++) {
		sum = (values.at(i) - mean) * (values.at(i + lag) - mean);
	}
	double corr = sum / ((values.size() - lag) * var);
	return corr;
}

/*
//https://www.geeksforgeeks.org/iterative-fast-fourier-transformation-polynomial-multiplication/
vector<Extractor::cd> Extractor::fft(std::vector<double>& values) {
	int n = values.size();
	vector<cd> res(n);
	bool pad = false;

	double power = log2(values.size());
	int power_round = ceil(power);
	//Pad vector if necessary
	if (abs(power - power_round) > 0.0001) {
		res.resize(pow(2, power_round) - res.size(), 0);
	}
	n = res.size();
	// bit reversal of the given array
	for (unsigned int i = 0; i < n; ++i) {
		int rev = bitReverse(i, power_round);
		res[i] = values[rev];
	}
	

	// j is iota
	const complex<double> J(0, 1);
	for (int s = 1; s <= power_round; ++s) {
		int m = 1 << s; // 2 power s
		int m2 = m >> 1; // m2 = m/2 -1
		cd w(1, 0);

		// principle root of nth complex
		// root of unity.
		cd wm = exp(J * (PI / m2));
		for (int j = 0; j < m2; ++j) {
			for (int k = j; k < n; k += m) {

				// t = twiddle factor
				cd t = w * res[k + m2];
				cd u = res[k];

				// similar calculating y[k]
				res[k] = u + t;

				// similar calculating y[k+n/2]
				res[k + m2] = u - t;
			}
			w *= wm;
		}
	}

	return res;
}

// Utility function for reversing the bits of given index x
unsigned int Extractor::bitReverse(unsigned int x, int log2n)
{
	int n = 0;
	for (int i = 0; i < log2n; i++)
	{
		n <<= 1;
		n |= (x & 1);
		x >>= 1;
	}
	return n;
}
*/
