#include "ExtractionHandler.h"

using namespace ed;
using namespace ex;
using namespace eh;
using namespace std;

Extractor extractor;

//Handler function for mean
double ExtractionHandler::handle_mean(string feature, vector<double> values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double value = extractor.mean(values);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for mean_abs_dev
double ExtractionHandler::handle_mean_abs_dev(string feature, vector<double> values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double mean = handle_mean("mean", values);
	double value = extractor.mean_abs_dev(values, mean);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for mean_geometric
double ExtractionHandler::handle_mean_geometric(string feature, vector<double> values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double value = extractor.mean_geometric(values);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for median
double ExtractionHandler::handle_median(string feature, vector<double> values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double value = extractor.median(values);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for median_abs_diff
double ExtractionHandler::handle_median_abs_diff(string feature, vector<double> values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double value = extractor.median_abs_diff(values);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for median_diff
double ExtractionHandler::handle_median_diff(string feature, vector<double> values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double value = extractor.median_diff(values);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for median_abs_dev, calls handle_median
double ExtractionHandler::handle_median_abs_dev(string feature, vector<double> values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double median = handle_median("median", values);
	double value = extractor.median_abs_dev(values, median);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for std_dev, calls handle_var
double ExtractionHandler::handle_std_dev(string feature, vector<double> values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double var = handle_var("var", values);
	double value = extractor.std_dev(values, var);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for avg_dev, calls handle_mean
double ExtractionHandler::handle_avg_dev(string feature, vector<double> values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double mean = handle_mean("mean", values);
	double value = extractor.avg_dev(values, mean);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for var, calls handle_mean
double ExtractionHandler::handle_var(string feature, vector<double> values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double mean = handle_mean("mean", values);
	double value = extractor.var(values, mean);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for abs_energy
double ExtractionHandler::handle_abs_energy(string feature, vector<double> values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double value = extractor.abs_energy(values);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for kurtosis, calls handle_mean and handle_std_dev
double ExtractionHandler::handle_kurtosis(string feature, vector<double> values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double mean = handle_mean("mean", values);
	double std_dev = handle_std_dev("std_dev", values);
	double value = extractor.kurtosis(values, mean, std_dev);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for skewness, calls handle_mean and handle_std_dev
double ExtractionHandler::handle_skewness(string feature, vector<double> values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double mean = handle_mean("mean", values);
	double std_dev = handle_std_dev("std_dev", values);
	double value = extractor.skewness(values, mean, std_dev);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

//Handler function for zero_cross
double ExtractionHandler::handle_zero_cross(string feature, vector<double> values) {
	if (ExtractionDelegate::doCache && ExtractionDelegate::calculated.count(feature)) {
		return ExtractionDelegate::calculated.at(feature);
	}

	double value = extractor.zero_cross(values);
	ExtractionDelegate::checkAndInsert(feature, value);
	return value;
}

