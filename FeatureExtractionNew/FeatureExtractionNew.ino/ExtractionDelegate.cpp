#include "ExtractionDelegate.h"

using namespace ed;
using namespace eh;
using namespace std;

bool ExtractionDelegate::doCache = false;
map<string, double> ExtractionDelegate::calculated;
ExtractionDelegate::handler_map ExtractionDelegate::handlers;
ExtractionHandler handler;

//Extracts the requested feature from the data
double ExtractionDelegate::extractOne(string feature, vector<double>& values) {
	auto iter = ExtractionDelegate::handlers.find(feature);
	if (!(iter == ExtractionDelegate::handlers.end())) {
		return (handler.*(iter->second))(feature, values);
	}

	return 0.0;
}

//Extracts the requested features from the data
vector<double> ExtractionDelegate::extractSome(vector<string>& features, vector<double>& values) {
	vector<double> results;
	for (string feature : features) {
		double value = extractOne(feature, values);
		results.push_back(value);
	}

	return results;
}

//Extracts all available features from the data
map<string, double> ExtractionDelegate::extractAll(vector<double>& values) {
	map<string, double> results;
	for (auto iter : ExtractionDelegate::handlers) {
		double value = (handler.*(iter.second))(iter.first, values);
		results.emplace(iter.first, value);
	}
	
	return results;
}

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
	ExtractionDelegate::handlers.emplace("mean_geometric", &ExtractionHandler::handle_mean_geometric);
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
}
/*
case "max": return handler.handle_max(feature, values);
case "abs_max": return handler.handle_abs_max(feature, values);
case "min": return handler.handle_min(feature, values);
case "last_location_of_max": return handler.handle_last_location_of_max(feature, values);
case "last_location_of_min": return handler.handle_last_location_of_min(feature, values);
case "first_location_of_max": return handler.handle_first_location_of_max(feature, values);
case "first_location_of_min": return handler.handle_first_location_of_min(feature, values);
case "mean_n_abs_max_values": return handler.handle_mean_n_abs_max_values(feature, values);

case "mean_abs_change": return handler.handle_mean_abs_change(feature, values);
case "mean_change": return handler.handle_mean_change(feature, values);
case "abs_sum_of_changes": return handler.handle_abs_sum_of_changes(feature, values);
case "change_quantile": return handler.handle_change_quantile(feature, values);

case "sum": return handler.handle_sum(feature, values);
case "range_count": return handler.handle_range_count(feature, values);
case "non_zero_count": return handler.handle_non_zero_count(feature, values);
case "count_above": return handler.handle_count_above(feature, values);
case "count_above_mean": return handler.handle_count_above_mean(feature, values);
case "count_below": return handler.handle_count_below(feature, values);
case "count_below_mean": return handler.handle_count_below_mean(feature, values);
case "root_mean_square": return handler.handle_root_mean_square(feature, values);
case "quantile": return handler.handle_quantile(feature, values);
case "interquartile_range": return handler.handle_interquartile_range(feature, values);
case "negative_turnings": return handler.handle_negative_turnings(feature, values);
case "positive_turnings": return handler.handle_positive_turnings(feature, values);

case "autocorrelation": return handler.handle_autocorrelation(feature, values);
case "fft": return handler.handle_fft(feature, values);
case "lpc": return handler.handle_lpc(feature, values);
case "lpcc": return handler.handle_lpcc(feature, values);
case "mfcc": return handler.handle_mfcc(feature, values);

default: return 0.0;
}
*/
