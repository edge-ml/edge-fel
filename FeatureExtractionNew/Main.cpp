#include "FeatureExtractionNew.ino/Extractor.h"
#include "FeatureExtractionNew.ino/ExtractionDelegate.h"
#include "FeatureExtractionNew.ino/ExtractionHandler.h"
#include "Data.h"
#include "ExtractionTest.h"
#include <vector>
#include <iostream>
#include <ctime>

using namespace eh;
using namespace ed;
using namespace std;
using namespace ex;

//missing: "mean_geometric","avg_dev", "change_quantile", "non_zero_count", "count_above",  "count_below",
map<string, double> featuresAndResults1k = { {"mean", 0.0048368} , {"mean_abs_dev", 1.9915990}, {"median", 0.060006}, {"median_abs_diff", 2.5281278},
	{"median_diff", -0.0531599}, {"median_abs_dev", 1.9915990}, {"std_dev", 2.3068508}, {"var", 5.3215605}, {"abs_energy", 5321.58}, {"kurtosis", -1.1818654},
	{"skewness", -0.0241072}, {"zero_cross", (double)529 / 1000}, {"max", 3.9785828}, {"abs_max", 3.9990850}, {"min", -3.9990850}, {"last_location_of_max", 110},
	{"last_location_of_min", 3}, {"first_location_of_max", 109}, {"first_location_of_min", 2}, {"mean_n_abs_max_values", 1.35463}, {"mean_abs_change", 2.74237},
	{"mean_change", 0.0028625 }, {"abs_sum_of_changes", 2739.63}, {"sum", 4.8367956}, {"range_count", 262}, {"count_above_mean", 0.506},
	{"count_below_mean", 0.494}, {"root_mean_square", 2.3068558}, {"quantile", 0.0600065}, {"interquartile_range", 3.9898933}, {"negative_turnings", 351},
	{"positive_turnings", 351}, {"autocorrelation",  -0.0264570} };



//missing: "change_quantile"
map<string, double> featuresAndResults10 = { {"mean", 0.3} , {"mean_abs_dev", 1.9}, {"median", 0.5}, {"median_abs_diff", 3.0},
	{"median_diff", 0.5}, {"median_abs_dev", 1.5}, {"std_dev", 2.2045407}, {"var", 4.85999999}, {"abs_energy", 49.5}, {"kurtosis", -0.7950007 /*-0.4411620*/},
	{"skewness", -0.3967680 /*-0.470509*/}, {"zero_cross", 0.3}, {"max", 3.5}, {"abs_max", 4.0}, {"min", -4.0}, {"last_location_of_max", 5},
	{"last_location_of_min", 7}, {"first_location_of_max", 5}, {"first_location_of_min", 7}, {"mean_n_abs_max", 2.25}, {"mean_abs_change", 2.777777},
	{"mean_change", 0.11111111 }, {"abs_sum_of_changes", 25.0}, {"sum", 3.0}, {"range_count", 0}, {"count_above_mean", 0.5},
	{"count_below_mean", 0.5}, {"root_mean_square", 2.224859}, {"quantile", 0.5}, {"interquartile_range", 3.0}, {"negative_turnings", 2},
	{"positive_turnings", 2}, {"autocorrelation",  0.0322359}, {"mean_geometric_abs", 1.75677 }, {"avg_dev", 1.9 }, {"non_zero_count", 9}, {"count_above", 0.5 }, {"count_below", 0.4} };

int main() {
	
	/*Extractor ex;
	vector<double> values = { 1,2,3,4 };
	vector<Extractor::cd> spectrum; 
	complex<double> first(10, 0.0);
	spectrum.push_back(first);
	complex<double> second(-2.0, 2.0);
	spectrum.push_back(second);
	complex<double> third(-2.0, 0.0);
	spectrum.push_back(third);
	complex<double> fourth(-2.0, -2.0);
	spectrum.push_back(fourth);

	testExtractSpectrum(values, spectrum);*/
	
		
	//testExtractAll(Data::values_ten, featuresAndResults10);
	//testExtractOne(Data::values_ten, featuresAndResults10);

	
	vector<double> values = Data::values_hundred;
	ExtractionDelegate delegate;
	delegate.fillHandlerMap();
	ExtractionDelegate::doCache = false;

	map<string, double> params = { {"mean_n_abs_max_n", 8}, {"change_quantile_lower", 0.1}, {"change_quantile_upper", 0.1},  {"range_count_lower",-1},
		{"range_count_upper", 1}, {"count_above_x", 0}, {"count_below_x", 0}, {"quantile_q", 0.5}, {"autocorrelation_lag", 1}, {"mfcc_sampling_rate", 100}, 
		{"mfcc_num_filter", 48}, {"mfcc_m", 1} };

	string caching = ExtractionDelegate::doCache ? "activated" : "not active";
	cout << "Starting feature extraction, caching " << caching << "\n";

	clock_t start, end;
	start = clock();
	map<string, double> results = delegate.extractAll(values, params);
	end = clock();

	for (auto single : results) {
		cout << single.first << ": " << single.second << "\n";
	}

	cout << "Feature extraction finished, took: " << ((double)end - start) / CLOCKS_PER_SEC << "\n";
	ExtractionDelegate::calculated.clear();

}


