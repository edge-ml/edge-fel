//#pragma once

#ifndef EXTRACTIONHANDLER_H
#define EXTRACTIONHANDLER_H

#include "Extractor.h"
#include "ExtractionDelegate.h"

namespace eh {

	class ExtractionHandler
	{

	public:
		
		double handle_mean(std::string, std::vector<double>&);
		double handle_mean_abs_dev(std::string, std::vector<double>&);
		double handle_mean_geometric(std::string, std::vector<double>&);
		double handle_median(std::string, std::vector<double>&);
		double handle_median_abs_diff(std::string, std::vector<double>&);
		double handle_median_diff(std::string, std::vector<double>&);
		double handle_median_abs_dev(std::string, std::vector<double>&);
		double handle_std_dev(std::string, std::vector<double>&);
		double handle_avg_dev(std::string, std::vector<double>&);
		double handle_var(std::string, std::vector<double>&);
		double handle_abs_energy(std::string, std::vector<double>&);
		double handle_kurtosis(std::string, std::vector<double>&);
		double handle_skewness(std::string, std::vector<double>&);
		double handle_zero_cross(std::string, std::vector<double>&);
		
		double handle_max(std::string, std::vector<double>&);
		double handle_abs_max(std::string, std::vector<double>&);
		double handle_min(std::string, std::vector<double>&);
		double handle_last_location_of_max(std::string, std::vector<double>&);
		double handle_last_location_of_min(std::string, std::vector<double>&);
		double handle_first_location_of_max(std::string, std::vector<double>&);
		double handle_first_location_of_min(std::string, std::vector<double>&);
		double handle_mean_n_abs_max(std::string, std::vector<double>&, double);

		double handle_mean_abs_change(std::string, std::vector<double>&);
		double handle_mean_change(std::string, std::vector<double>&);
		double handle_abs_sum_of_changes(std::string, std::vector<double>&);
		double handle_change_quantile(std::string, std::vector<double>&, double, double, std::string);

		double handle_sum(std::string, std::vector<double>&);
		double handle_range_count(std::string, std::vector<double>&, double, double);
		double handle_non_zero_count(std::string, std::vector<double>&);
		double handle_count_above(std::string, std::vector<double>&, double);
		double handle_count_above_mean(std::string, std::vector<double>&);
		double handle_count_below(std::string, std::vector<double>&, double);
		double handle_count_below_mean(std::string, std::vector<double>&);
		double handle_root_mean_square(std::string, std::vector<double>&);
		double handle_quantile(std::string, std::vector<double>&, double);
		double handle_interquartile_range(std::string, std::vector<double>&);
		double handle_negative_turnings(std::string, std::vector<double>&);
		double handle_positive_turnings(std::string, std::vector<double>&);

		double handle_autocorrelation(std::string, std::vector<double>&, double);
		
		//std::vector<ex::Extractor::cd> handle_fft(std::string, std::vector<double>&);
		/*
		double handle_lpc(std::string, std::vector<double>&);
		double handle_lpcc(std::string, std::vector<double>&);
		double handle_mfcc(std::string, std::vector<double>&);
		*/
	};

}

#endif