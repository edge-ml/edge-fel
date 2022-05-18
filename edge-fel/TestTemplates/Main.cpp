#include "FeatureExtractionNew.ino/Extractor.h"
#include "FeatureExtractionNew.ino/ExtractionDelegate.h"
#include "FeatureExtractionNew.ino/ExtractionHandler.h"
#include "Data.h"
#include "ExtractionTest.h"
#include <vector>
#include <iostream>
#include <ctime>
#include "FeatureExtractionNew.ino/Cmplx.h"

#include <chrono>

using namespace eh;
using namespace ed;
using namespace std;
using namespace ex;
using namespace co;

//missing: "mean_geometric","avg_dev", "change_quantile", "non_zero_count", "count_above",  "count_below",
map<string, float> featuresAndResults1k = { {"mean", 0.0048368} , {"mean_abs_dev", 1.9915990}, {"median", 0.060006}, {"median_abs_changes", 2.5281278},
	{"median_changes", -0.0531599}, {"median_abs_dev", 1.9915990}, {"std_dev", 2.3068508}, {"var", 5.3215605}, {"abs_energy", 5321.58}, {"kurtosis", -1.1818654},
	{"skewness", -0.0241072}, {"zero_cross", (float)529 / 1000}, {"max", 3.9785828}, {"abs_max", 3.9990850}, {"min", -3.9990850}, {"last_location_of_max", 110},
	{"last_location_of_min", 3}, {"first_location_of_max", 109}, {"first_location_of_min", 2}, {"mean_n_abs_max_values", 1.35463}, {"mean_abs_changes", 2.74237},
	{"mean_changes", 0.0028625 }, {"abs_sum_of_changes", 2739.63}, {"sum", 4.8367956}, {"range_count", 262}, {"count_above_mean", 0.506},
	{"count_below_mean", 0.494}, {"root_mean_square", 2.3068558}, {"quantile", 0.0600065}, {"interquartile_range", 3.9898933}, {"negative_turnings", 351},
	{"positive_turnings", 351}, {"autocorrelation",  -0.0264570} };



//missing: "change_quantile"
map<string, float> featuresAndResults10 = { {"mean", 0.3} , {"mean_abs_dev", 1.9}, {"median", 0.5}, {"median_abs_changes", 3.0},
	{"median_changes", 0.5}, {"median_abs_dev", 1.5}, {"std_dev", 2.2045407}, {"var", 4.85999999}, {"abs_energy", 49.5}, {"kurtosis", -0.7950007 /*-0.4411620*/},
	{"skewness", -0.3967680 /*-0.470509*/}, {"zero_cross", 0.3}, {"max", 3.5}, {"abs_max", 4.0}, {"min", -4.0}, {"last_location_of_max", 5},
	{"last_location_of_min", 7}, {"first_location_of_max", 5}, {"first_location_of_min", 7}, {"mean_n_abs_max", 2.25}, {"mean_abs_changes", 2.777777},
	{"mean_changes", 0.11111111 }, {"abs_sum_of_changes", 25.0}, {"sum", 3.0}, {"range_count", 0}, {"count_above_mean", 0.5},
	{"count_below_mean", 0.5}, {"root_mean_square", 2.224859}, {"quantile", 0.5}, {"interquartile_range", 3.0}, {"negative_turnings", 2},
	{"positive_turnings", 2}, {"autocorrelation",  0.0322359}, {"mean_geometric_abs", 1.75677 }, {"avg_dev", 1.9 }, {"non_zero_count", 9}, {"count_above", 0.5 }, {"count_below", 0.4} };

int main() {

	//testExtractAll(Data::values_ten, featuresAndResults10);
	//testExtractOne(Data::values_ten, featuresAndResults10);

	map<string, float> params = { {"mean_n_abs_max_n", 8}, {"change_quantile_lower", -0.1}, {"change_quantile_upper", 0.1}, {"change_quantile_aggr", 0},
			{"range_count_lower", -1}, {"range_count_upper", 1}, {"count_above_x", 0}, {"count_below_x", 0}, {"quantile_q", 0.5}, {"autocorrelation_lag", 1} };

	/*vector<string> features:tsfresh = { "abs_energy" , "abs_sum_of_changes", "autocorrelation", "count_above", "count_above_mean", "count_below", "count_below_mean", "first_location_of_max",
	"first_location_of_min", "kurtosis", "last_location_of_max", "last_location_of_min", "max", "mean", "mean_abs_changes", "mean_changes", "median", "min", "zero_cross",
	"quantile","range_count", "root_mean_square", "skewness", "std_dev", "sum", "var" };*/

	/*vector<string> features_tsfel = { "mean", "mean_abs_dev", "median", "median_abs_changes", "median_changes", "median_abs_dev", "std_dev",
			"var", "abs_energy", "kurtosis", "skewness", "zero_cross", "max", "min", "mean_abs_changes", "mean_changes",
			"abs_sum_of_changes", "root_mean_square", "interquartile_range", "negative_turnings",
			"positive_turnings", "autocorrelation" };*/

	vector<string> features = { "length", "mean", "var", "std_dev", "avg_dev", "skewness", "kurtosis", "zero_cross", "root_mean_square", "sum", "min", "max", "non_zero_count" };

	vector<float> values = Data::values_thousand;
	ExtractionDelegate delegate;
	ExtractionDelegate::doCache = false;

	map<string, long long> runtimes;
	for (auto f : features) {
		runtimes.emplace(f, 0);
	}

	for (int i = 0; i < 100; i++) {
		for (auto iter : runtimes) {
			auto start = std::chrono::steady_clock::now();
			float result = delegate.extractOne(iter.first, values, params);
			auto end = std::chrono::steady_clock::now();
			auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
			runtimes[iter.first] = iter.second +=elapsed.count();
		}
	}
	long long sum = 0;
	for (auto iter : runtimes) {
		cout << iter.first << " took " << iter.second / 100.0f << " nanoseconds.\n";
		sum += iter.second / 100.0f;
	}
	cout << "Total time: " << sum << " nanoseconds.\n";

	sum = 0;
	for (int i = 0; i < 100; i++) {
		auto start = std::chrono::steady_clock::now();
		map<string, float> result = delegate.extractSome(features, values, params);
		auto end = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		sum += elapsed.count();
	}
	cout << "Total time with extract some: " << sum / 100.0f << " nanoseconds.\n";

	ExtractionDelegate::doCache = true;
	sum = 0;
	for (int i = 0; i < 100; i++) {
		auto start = std::chrono::steady_clock::now();
		map<string, float> result = delegate.extractSome(features, values, params);
		auto end = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		sum += elapsed.count();
		delegate.calculated.clear();
	}
	cout << "Total time with extract some and caching: " << sum / 100.0f << " nanoseconds.\n";
}


