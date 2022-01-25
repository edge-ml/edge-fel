#include "ExtractionTest.h"

using namespace eh;
using namespace ed;
using namespace std;
using namespace ex;
using namespace co;

map<string, double> params = { {"mean_n_abs_max_n", 8}, {"change_quantile_lower", 0.1}, {"change_quantile_upper", 0.1},  {"change_quantile_aggr", 0}, 
		{"range_count_lower",-1}, {"range_count_upper", 1}, {"count_above_x", 0}, {"count_below_x", 0}, {"quantile_q", 0.5}, {"autocorrelation_lag", 1} };

int testExtractOne(vector<double> values, map<string, double> featuresAndResults) {
	ExtractionDelegate delegate;
	ExtractionDelegate::doCache = true;
	int errorCount = 0;

	for (auto iter : featuresAndResults) {
		double value = delegate.extractOne(iter.first, values, params);
		if (abs(iter.second - value) > 0.00001) {
			errorCount++;
		}
		cout << iter.first << "\n";
		cout << "expected: " << iter.second << " actual: " << value << "\n" << "\n";
		
	}
	if (!errorCount) {
		cout << "ALL TESTS SUCCESSFUL!!" << "\n";
	}
	else {
		cout << errorCount << " TESTS FAILED!!" << "\n";
	}
	return 0;
}

int testExtractAll(vector<double> values, map<string, double> featuresAndResults) {
	ExtractionDelegate delegate;
	ExtractionDelegate::doCache = false;
	int errorCount = 0;

	map<string, double> res = delegate.extractAll(values, params);
	for (auto result : res) {
		auto iter = featuresAndResults.find(result.first);
		if (!(iter == featuresAndResults.end())) {
			if (abs(result.second - featuresAndResults.at(result.first)) > 0.00001) {
				errorCount++;
			}
			cout << result.first << "\n";
			cout << "expected: " << featuresAndResults.at(result.first) << " actual: " << result.second << "\n" << "\n";
		}
	}

	if (!errorCount) {
		cout << "ALL TESTS SUCCESSFUL!!" << "\n";
	}
	else {
		cout << errorCount << " TESTS FAILED!!" << "\n";
	}

	return 0;
}

int testExtractSpectrum(vector<double> values, vector<cd> coefficients) {
	ExtractionDelegate delegate;
	ExtractionDelegate::doCache = false;
	vector<cd> res = delegate.extractSpectrum(values);
	for (int i = 0; i < res.size(); i++) {
		cout << "expected: (" << coefficients[i].real << "," << coefficients[i].imag << ") ";
		cout << "actual : (" << res[i].real << "," << res[i].imag << ")" << "\n";
	}

	return 0;
}