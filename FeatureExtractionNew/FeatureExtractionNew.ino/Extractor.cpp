#include "Extractor.h"
#include <cmath>
#include <iostream>

using namespace ex;
using namespace std;
using namespace co;

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
double Extractor::mean_geometric_abs(vector<double> values) {
	for (auto& value : values) {
		if (value != 0) {
			value = log(abs(value));
		}
	}
	double log_mean = mean(values);
	return exp(log_mean);

	/*
	double product = 1;
	for (auto& value : values) {
		if (value != 0) {
			product = product * abs(value);
		}
	}
	return pow(product, ((double)1 / values.size()));
	*/
}

//Helper method for median inside extractors
double Extractor::call_by_reference_median(vector<double>& values) {
  sort(values.begin(), values.end());
  int size = values.size();
  if (size % 2 == 0) {
    int mid = size / 2 - 1;
    return (values.at(mid) + values.at(mid + 1)) / 2;
  }
  
  return values.at(size / 2);
}

//Returns the median of the values
double Extractor::median(vector<double> values) {
	sort(values.begin(), values.end());
	int size = values.size();
	if (size % 2 == 0) {
		int mid = size / 2 - 1;
		return (values.at(mid) + values.at(mid + 1)) / 2;
	}
  
	return values.at(size / 2);
}

//Returns the median of all absolute changes
double Extractor::median_abs_diff(vector<double>& values) {
	vector<double> abs_changes;
	abs_changes.reserve(values.size());
	for (size_t i = 0; i < values.size() - 1; i++) {
		double diff = abs(values.at(i) - values.at(i + 1));
		abs_changes.push_back(diff);
	}

	return call_by_reference_median(abs_changes);
}

//Returns the median of all changes 
double Extractor::median_diff(vector<double>& values) {
	vector<double> changes;
	changes.reserve(values.size());
	for (size_t i = 0; i < values.size() - 1; i++) {
		double diff = values.at(i + 1) - values.at(i);
		changes.push_back(diff);
	}
 
	return call_by_reference_median(changes);
}

//Returns the median of all absolute deviations to the median
double Extractor::median_abs_dev(vector<double>& values, double my_median) {
	vector<double> abs_dev;
	abs_dev.reserve(values.size());
	for (auto& value : values) {
		double dev = abs(value - my_median);
		abs_dev.push_back(dev);
	}
 
  return call_by_reference_median(abs_dev);
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

//Returns the percentage of zero crossings of two consecutive values
double Extractor::zero_cross(vector<double>& values) {
	double crosses = 0;
	for (size_t i = 0; i < values.size() - 1; i++) {
		if (values.at(i) * values.at(i + 1) < 0) {
			crosses++;
		}
	}

	return crosses / values.size();
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
		if (abs(value) > max) {
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
	double index = 0;
	for (int i = 1; i < values.size(); i++) {
		if (abs(values.at(i) - max) < numeric_limits<double>::epsilon()) {
			return i;
		}
	}
	return index;
}

//Returns the first location of the minimum value
double Extractor::first_location_of_min(vector<double>& values, double min) {
	double index = 0;
	for (int i = 1; i < values.size(); i++) {
		if (abs(values.at(i) - min) < numeric_limits<double>::epsilon()) {
			return i;
		}
	}
	return index;
}

//Returns the average of the n largest absolute values
double Extractor::mean_n_abs_max(vector<double> values, int n) {
	if (n > values.size()) {
		return 0.0;
	}
	for (auto& value : values) {
		value = abs(value);
	}
	sort(values.begin(), values.end());
	double sum = 0;
	for (int i = values.size() - 1; i > values.size() - 1 - n; i--) {
		sum += abs(values.at(i));
	}
	return sum / n;
}


//Returns the mean of the absolute differences of consecutive values
double Extractor::mean_abs_change(vector<double>& values) {
	vector<double> abs_changes;
	abs_changes.reserve(values.size());
	for (size_t i = 0; i < values.size() - 1; i++) {
		double diff = abs(values.at(i) - values.at(i + 1));
		abs_changes.push_back(diff);
	}

	return mean(abs_changes);
}

//Returns the mean of differences of consecutive values
double Extractor::mean_change(vector<double>& values) {
	vector<double> changes;
	changes.reserve(values.size());
	for (size_t i = 0; i < values.size() - 1; i++) {
		double diff = values.at(i+1) - values.at(i);
		changes.push_back(diff);
	}

	return mean(changes);
}

//Returns the sum of the absolute differences of consecutive values
double Extractor::abs_sum_of_changes(vector<double>& values) {
	vector<double> abs_changes;
	abs_changes.reserve(values.size());
	for (size_t i = 0; i < values.size() - 1; i++) {
		double diff = abs(values.at(i) - values.at(i + 1));
		abs_changes.push_back(diff);
	}

	return sum(abs_changes);
}

//Calculates the absolute differences of all values between the two quantiles and applies the aggregation function
double Extractor::change_quantile(vector<double> values, double lower, double upper, int aggr) {
	sort(values.begin(), values.end());
 
	for (size_t i = lower; i <= upper; i++) {
		double diff = abs(values.at(i) - values.at(i + 1));
		values.at(i) = diff;
	}

	if (aggr == 0) {
		return sum(values);
	} 
	else if (aggr == 1) {
		return mean(values);
	}
	else if (aggr == 2) {
		return call_by_reference_median(values);
	}
	else if (aggr == 3) {
		return var(values, mean(values));
	}
	else if (aggr == 4) {
		return std_dev(values, var(values, mean(values)));
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
	for (auto& value : values) {
		if (value > lower && value < upper) {
			sum += value;
		}
	}
	return sum;
}

//Returns the number of non-zero values
double Extractor::non_zero_count(vector<double>& values) {
	double amount = 0;
	for (auto& value : values) {
		if (value != 0) {
			amount++;
		}
	}
	return amount;
}

//Returns the percentage of values greater than x
double Extractor::count_above(vector<double>& values, double x) {
	double amount = 0;
	for (auto& value : values) {
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
	for (auto& value : values) {
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
double Extractor::root_mean_square(vector<double>& values, double energy) {
	return sqrt(energy/values.size());
}

//Returns the value which is greater than q*n percent of all values
double Extractor::quantile(vector<double> values, double q) {
  sort(values.begin(), values.end());
	
	double nq = q * values.size();
	int i = floor(nq);
	if (abs(nq - i) > 0.00000001) {
		i= ceil(nq);
		return values.at(i - 1);
	}
	else {
		return (values.at(i - 1) + values.at(i)) / 2;
	}
}

//Returns the difference of the 3/4 and 1/4 quantiles
double Extractor::interquartile_range(vector<double>& values) {
  double upper = quantile(values, 0.75);
  double lower = quantile(values, 0.25);
	return upper - lower;
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

//Calculates a mfc coefficient
double Extractor::mfcc(vector<cd>& values, int samplingRate, int numFilters, int m) {
	return getCoefficient(values, samplingRate, numFilters, values.size(), m);
}

//Calculates an estimation of the autocorrelation for a specified lag
double Extractor::autocorrelation(vector<double>& values, int lag, double mean, double var) {
	double sum = 0;
	for (size_t i = 0; i < values.size() - lag; i++) {
		sum = (values.at(i) - mean) * (values.at(i + lag) - mean);
	}
	double corr = sum / ((values.size() - (double) lag) * pow(var,2));
	return corr;
}


//https://www.geeksforgeeks.org/iterative-fast-fourier-transformation-polynomial-multiplication/
vector<cd> Extractor::fft(std::vector<double>& values) {
	int n = values.size();
	double power = log2(values.size());
	int power_round = ceil(power);

	//Pad vector if necessary
	if (abs(power - power_round) > 0.0001) {
		n = pow(2, power_round);
	}
	vector<cd> res;
	res.reserve(n);
  
	for (int i = 0; i < n; i++) {
		cd c(0, 0);
		res.push_back(c);
	}
	// bit reversal of the given array
	for (unsigned int i = 0; i < n; i++) {
		int rev = bitReverse(i, power_round);
		cd c;
		if (rev < values.size()) {
			c.real = values[rev];
		}
		res.at(i) = c;
	}
	
	// j is iota
	const cd J(0, 1);
	for (int s = 1; s <= power_round; ++s) {
		int m = 1 << s; // 2 power s
		int m2 = m >> 1; // m2 = m/2 -1
		cd w(1, 0);

		// principle root of nth complex
		// root of unity.
		cd wm = e(mul(J, pi / m2)); 
		for (int j = 0; j < m2; ++j) {
			for (int k = j; k < n; k += m) {
				// t = twiddle factor
				cd t = mul(w, res[k + m2]);
				cd u = res[k];

				// similar calculating y[k]
				res[k] = add(u, t);

				// similar calculating y[k+n/2]
				res[k + m2] = sub(u, t);
			}
			w = mul(w, wm);
		}
	}
	return res;
}

// Utility function for reversing the bits of given index x
unsigned int Extractor::bitReverse(unsigned int x, int log2n) {
	int n = 0;
	for (int i = 0; i < log2n; i++)
	{
		n <<= 1;
		n |= (x & 1);
		x >>= 1;
	}
	return n;
}

//Calculates n lpc coefficients
vector<double> Extractor::lpc(vector<double>& autoc, int n) {
	vector<double> lpc(n - 1, 0);
	double error = autoc[0];
	if (error == 0.0) {
		return lpc;
	}

	for (int i = 0; i < n - 1; i++) {
		/* Sum up this iteration's reflection coefficient. */
		double r = -autoc[i + 1];
		for (int j = 0; j < i; j++) {
			r -= lpc[j] * autoc[i - j];
		}
		r /= error;

		/* Update LPC coefficients and total error. */
		lpc[i] = r;
		int j;
		for (j = 0; j < i / 2; j++)
		{
			double tmp = lpc[j];
			lpc[j] = r * lpc[i - 1 - j];
			lpc[i - 1 - j] += r * tmp;
		}
		if (i % 2) {
			lpc[j] += lpc[j] * r;
		}
		error *= 1 - r * r;
	}
	return lpc;
}

vector<double> Extractor::lpcc(vector<double>& lpc_coeffs, int cep_length) {
	int order = lpc_coeffs.size() - 1; /* Eventually change this to Q = 3/2 p as suggested in Rabiner */
	vector<double> lpcc(cep_length, 0);

	for (int n = 1; n <= order && n <= cep_length; n++) {
		double sum = 0.0;
		for (int k = 1; k < n; k++) {
			sum += k * lpcc[k - 1] * lpc_coeffs[n - k];
		}
		lpcc[n - 1] = lpc_coeffs[n] + sum / n;
	}

	/* be wary of these interpolated values */
	for (int n = order + 1; n <= cep_length; n++) {
		double sum = 0.0;
		for (int k = n - (order - 1); k < n; k++)
			sum += k * lpcc[k - 1] * lpc_coeffs[n - k];
		lpcc[n - 1] = sum / n;
	}

	return lpcc;
}
