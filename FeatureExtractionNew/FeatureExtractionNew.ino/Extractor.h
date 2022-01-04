//#pragma once

#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include <string>
#include <vector>
#include <algorithm>

namespace ex {

	class Extractor
	{
	public:
		double mean(std::vector<double>&);
		double mean_abs_dev(std::vector<double>&, double);
		double mean_geometric(std::vector<double>);
		double median(std::vector<double>);
		double median_abs_diff(std::vector<double>&);
		double median_diff(std::vector<double>&);
		double median_abs_dev(std::vector<double>&, double);
		double std_dev(std::vector<double>&, double);
		double avg_dev(std::vector<double>&, double);
		double var(std::vector<double>&, double);
		double abs_energy(std::vector<double>&);
		double kurtosis(std::vector<double>&, double, double);
		double skewness(std::vector<double>&, double, double);
		double zero_cross(std::vector<double>&);

		/*double max(vector<double>);
		double abs_max(vector<double>);
		double min(vector<double>);
		double last_location_of_max(vector<double>);
		double last_location_of_min(vector<double>);
		double first_location_of_max(vector<double>);
		double first_location_of_min(vector<double>);
		double mean_n_abs_max_values(vector<double>);

		double mean_abs_change(vector<double>);
		double mean_change(vector<double>);
		double abs_sum_of_changes(vector<double>);
		double change_quantile(vector<double>);

		double sum(vector<double>);
		double range_count(vector<double>);
		double non_zero_count(vector<double>);
		double count_above(vector<double>);
		double count_above_mean(vector<double>);
		double count_below(vector<double>);
		double count_below_mean(vector<double>);
		double root_mean_square(vector<double>);
		double quantile(vector<double>);
		double interquartile_range(vector<double>);
		double negative_turnings(vector<double>);
		double positive_turnings(vector<double>);

		double autocorrelation(vector<double>, vector<double>);
		double fft(vector<double>, vector<double>);
		double lpc(vector<double>, vector<double>);
		double lpcc(vector<double>, vector<double>);
		double mfcc(vector<double>, vector<double>);*/

	};

}
#endif
