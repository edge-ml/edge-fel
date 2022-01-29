//#pragma once

#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include <string>
#include <vector>
#include <algorithm>
#include "libmfcc.h"
#include "Cmplx.h"

namespace ex {

	class Extractor
	{
	public:

		double mean(std::vector<double>&);
		double mean_abs_dev(std::vector<double>&, double);
		double mean_geometric_abs(std::vector<double>);
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

		double max(std::vector<double>&);
		double abs_max(std::vector<double>&);
		double min(std::vector<double>&);
		double last_location_of_max(std::vector<double>&, double);
		double last_location_of_min(std::vector<double>&, double);
		double first_location_of_max(std::vector<double>&, double);
		double first_location_of_min(std::vector<double>&, double);
		double mean_n_abs_max(std::vector<double>, int);

		double mean_abs_change(std::vector<double>&);
		double mean_change(std::vector<double>&);
		double abs_sum_of_changes(std::vector<double>&);
		double change_quantile(std::vector<double>, double, double, int);

		double sum(std::vector<double>&);
		double range_count(std::vector<double>&, double, double);
		double non_zero_count(std::vector<double>&);
		double count_above(std::vector<double>&, double);
		double count_above_mean(std::vector<double>&, double);
		double count_below(std::vector<double>&, double);
		double count_below_mean(std::vector<double>&, double);
		double root_mean_square(std::vector<double>&, double);
		double quantile(std::vector<double>, double);
		double interquartile_range(std::vector<double>&);
		double negative_turnings(std::vector<double>&);
		double positive_turnings(std::vector<double>&);

		double autocorrelation(std::vector<double>&, int, double, double);
		double mfcc(std::vector<co::cd>&, int, int, int);
		std::vector<co::cd> fft(std::vector<double>&);
		std::vector<double> lpc(std::vector<double>&, int);
		std::vector<double> lpcc(std::vector<double>&, int);
		
	
	private:
		unsigned int bitReverse(unsigned int, int);
    double call_by_reference_median(std::vector<double>&);
	};

}
#endif
