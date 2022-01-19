#include "ExtractionDelegate.h"

using namespace ed;
using namespace eh;
using namespace std;

bool ExtractionDelegate::doCache = false;
map<string, double> ExtractionDelegate::calculated;
ExtractionDelegate::handler_map ExtractionDelegate::handlers;
ExtractionHandler handler;
vector<string> ExtractionDelegate::parameterFeatures = {"mean_n_abs_max",  "change_quantile", "range_count", "count_above", "count_below", "quantile", "autocorrelation", "mfcc" };

//Extracts the requested feature from the data
double ExtractionDelegate::extractOne(string feature, vector<double>& values, map<string, double>& params) {
		if (feature == "mean_n_abs_max") {
			return handler.handle_mean_n_abs_max(feature, values, params.at("mean_n_abs_max_n"));
		}
		else if (feature == "change_quantile") {
			return handler.handle_change_quantile(feature, values, params.at("change_quantile_lower"), params.at("change_quantile_upper"), "sum");
		}
		else if (feature == "range_count") {
			return handler.handle_range_count(feature, values, params.at("range_count_lower"), params.at("range_count_upper"));
		}
		else if (feature == "count_above") {
			return handler.handle_count_above(feature, values, params.at("count_above_x"));
		}
		else if (feature == "count_below") {
			return handler.handle_count_below(feature, values, params.at("count_below_x"));
		}
		else if (feature == "quantile") {
			return handler.handle_quantile(feature, values, params.at("quantile_q"));
		}
		else if (feature == "autocorrelation") {
			return handler.handle_autocorrelation(feature, values, params.at("autocorrelation_lag"));
		}
		else if (feature == "mfcc") {
			//return handler.handle_mfcc("mfcc", values, params.at("mfcc_sampling_rate"), params.at("mfcc_num_filter"), params.at("mfcc_m"));
		}
		else {
			auto iter = ExtractionDelegate::handlers.find(feature);
			if (!(iter == ExtractionDelegate::handlers.end())) {
				return (handler.*(iter->second))(feature, values);
			}
			return 0.0;
		}
	
}

//Extracts the requested features from the data
map<string, double> ExtractionDelegate::extractSome(vector<string>& features, vector<double>& values, map<string, double>& params) {
	map<string, double> results;
	for (string feature : features) {
		double value = extractOne(feature, values, params);
		results.emplace(feature, value);
	}
    
	return results;
}

//Extracts all available features from the data
map<string, double> ExtractionDelegate::extractAll(vector<double>& values, map<string, double>& params) {
	map<string, double> results;
	for (auto iter : ExtractionDelegate::handlers) {
		double value = (handler.*(iter.second))(iter.first, values);
		results.emplace(iter.first, value);
	}
	map<string, double> parameterFeatures = extractSome(ExtractionDelegate::parameterFeatures, values, params);
	results.insert(parameterFeatures.begin(), parameterFeatures.end());
	return results;
}
/*
//Extracts the spectrum of the times series with fft
vector<ex::Extractor::cd> ExtractionDelegate::extractSpectrum(vector<double>& values) {
	return handler.handle_fft("fft", values);
}*/


//Helper method for fail-fast cache check and insertion
void ExtractionDelegate::checkAndInsert(string feature, double value) {
	if (doCache && !calculated.count(feature)) {
		calculated.emplace(feature, value);
	}
}

//Initializes the handler map 
void ExtractionDelegate::fillHandlerMap() {
	ExtractionDelegate::handlers.emplace("mean", &ExtractionHandler::handle_mean);
	ExtractionDelegate::handlers.emplace("mean_abs_dev", &ExtractionHandler::handle_mean_abs_dev);
	ExtractionDelegate::handlers.emplace("mean_geometric_abs", &ExtractionHandler::handle_mean_geometric_abs);
	ExtractionDelegate::handlers.emplace("median", &ExtractionHandler::handle_median);
	ExtractionDelegate::handlers.emplace("median_abs_diff", &ExtractionHandler::handle_median_abs_diff);
	ExtractionDelegate::handlers.emplace("median_diff", &ExtractionHandler::handle_median_diff);
	ExtractionDelegate::handlers.emplace("median_abs_dev", &ExtractionHandler::handle_median_abs_dev);
	ExtractionDelegate::handlers.emplace("std_dev", &ExtractionHandler::handle_std_dev);
	ExtractionDelegate::handlers.emplace("avg_dev", &ExtractionHandler::handle_avg_dev);
	ExtractionDelegate::handlers.emplace("var", &ExtractionHandler::handle_var);
	ExtractionDelegate::handlers.emplace("abs_energy", &ExtractionHandler::handle_abs_energy);
	ExtractionDelegate::handlers.emplace("kurtosis", &ExtractionHandler::handle_kurtosis);
	ExtractionDelegate::handlers.emplace("skewness", &ExtractionHandler::handle_skewness);
	ExtractionDelegate::handlers.emplace("zero_cross", &ExtractionHandler::handle_zero_cross);

	ExtractionDelegate::handlers.emplace("max", &ExtractionHandler::handle_max);
	ExtractionDelegate::handlers.emplace("abs_max", &ExtractionHandler::handle_abs_max);
	ExtractionDelegate::handlers.emplace("min", &ExtractionHandler::handle_min);
	ExtractionDelegate::handlers.emplace("last_location_of_max", &ExtractionHandler::handle_last_location_of_max);
	ExtractionDelegate::handlers.emplace("last_location_of_min", &ExtractionHandler::handle_last_location_of_min);
	ExtractionDelegate::handlers.emplace("first_location_of_max", &ExtractionHandler::handle_first_location_of_max);
	ExtractionDelegate::handlers.emplace("first_location_of_min", &ExtractionHandler::handle_first_location_of_min);

	ExtractionDelegate::handlers.emplace("mean_abs_change", &ExtractionHandler::handle_mean_abs_change);
	ExtractionDelegate::handlers.emplace("mean_change", &ExtractionHandler::handle_mean_change);
	ExtractionDelegate::handlers.emplace("abs_sum_of_changes", &ExtractionHandler::handle_abs_sum_of_changes);

	ExtractionDelegate::handlers.emplace("sum", &ExtractionHandler::handle_sum);
	ExtractionDelegate::handlers.emplace("non_zero_count", &ExtractionHandler::handle_non_zero_count);
	ExtractionDelegate::handlers.emplace("count_above_mean", &ExtractionHandler::handle_count_above_mean);
	ExtractionDelegate::handlers.emplace("count_below_mean", &ExtractionHandler::handle_count_below_mean);
	ExtractionDelegate::handlers.emplace("root_mean_square", &ExtractionHandler::handle_root_mean_square);
	ExtractionDelegate::handlers.emplace("interquartile_range", &ExtractionHandler::handle_interquartile_range);
	ExtractionDelegate::handlers.emplace("negative_turnings", &ExtractionHandler::handle_negative_turnings);
	ExtractionDelegate::handlers.emplace("positive_turnings", &ExtractionHandler::handle_positive_turnings);
	
}
