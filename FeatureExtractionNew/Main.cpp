#include "FeatureExtractionNew.ino/Extractor.h"
#include "FeatureExtractionNew.ino/ExtractionDelegate.h"
#include "FeatureExtractionNew.ino/ExtractionHandler.h"
#include "Data.h"
#include <vector>
#include <iostream>

using namespace eh;
using namespace ed;
using namespace std;
using namespace ex;

int main() {
	vector<double> values = Data::values_ten_thousand;
	/*values.insert(values.end(), Data::values_ten_thousand.begin(), Data::values_ten_thousand.end());
	values.insert(values.end(), Data::values_ten_thousand.begin(), Data::values_ten_thousand.end());
	values.insert(values.end(), Data::values_ten_thousand.begin(), Data::values_ten_thousand.end());
	values.insert(values.end(), Data::values_ten_thousand.begin(), Data::values_ten_thousand.end());
	values.insert(values.end(), Data::values_ten_thousand.begin(), Data::values_ten_thousand.end());
	values.insert(values.end(), Data::values_ten_thousand.begin(), Data::values_ten_thousand.end());
	values.insert(values.end(), Data::values_ten_thousand.begin(), Data::values_ten_thousand.end());
	values.insert(values.end(), Data::values_ten_thousand.begin(), Data::values_ten_thousand.end());
	values.insert(values.end(), Data::values_ten_thousand.begin(), Data::values_ten_thousand.end());*/
	//cout << sizeof(vector<double>) + sizeof(double)*values.size() << "\n";

	for (int i = 0; i < 10; i++) {
		ExtractionDelegate delegate;
		delegate.fillHandlerMap();
		ExtractionDelegate::doCache = true;

		map<string, double> params = { {"mean_n_abs_max_n", 8}, {"change_quantile_lower", 0.1}, {"change_quantile_upper", 0.1},  {"range_count_lower",-1}, 
			{"range_count_upper", 1}, {"count_above_x", 0}, {"count_below_x", 0}, {"quantile_q", 0.5}, {"autocorrelation_lag", 1} };


		string caching = ExtractionDelegate::doCache ? "activated" : "not active";
		cout << "Starting feature extraction, caching " << caching << "\n";

		clock_t start, end;
		start = clock();
		map<string, double> results = delegate.extractAll(values, params);
		end = clock();

		/*
		for (auto single : results) {
			cout << single.first << ": " << single.second << "\n";
		}*/

		cout << "Feature extraction finished, took: " << ((double)end - start) / CLOCKS_PER_SEC << "\n";
		ExtractionDelegate::calculated.clear();
	}
}


