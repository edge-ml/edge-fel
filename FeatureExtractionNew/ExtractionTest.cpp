#include "ExtractionTest.h"

using namespace eh;
using namespace ed;
using namespace std;
using namespace ex;

map<string, double> params = { {"mean_n_abs_max_n", 8}, {"change_quantile_lower", 0.1}, {"change_quantile_upper", 0.1},  {"range_count_lower",-1},
		{"range_count_upper", 1}, {"count_above_x", 0}, {"count_below_x", 0}, {"quantile_q", 0.5}, {"autocorrelation_lag", 1} };

int testExtractOne(vector<double> values, map<string, double> featuresAndResults) {
	ExtractionDelegate delegate;
	delegate.fillHandlerMap();
	ExtractionDelegate::doCache = true;

	for (auto iter : featuresAndResults) {
		double value = delegate.extractOne(iter.first, values, params);
		cout << iter.first << "\n";
		cout << "expected: " << iter.second << " actual: " << value << "\n" << "\n";
	}

	return 0;
}

int testExtractAll(vector<double> values, map<string, double> featuresAndResults) {
	ExtractionDelegate delegate;
	delegate.fillHandlerMap();
	ExtractionDelegate::doCache = false;

	map<string, double> res = delegate.extractAll(values, params);
	for (auto result : res) {
		auto iter = featuresAndResults.find(result.first);
		if (!(iter == featuresAndResults.end())) {
			cout << result.first << "\n";
			cout << "expected: " << featuresAndResults.at(result.first) << " actual: " << result.second << "\n" << "\n";
		}
	}

	return 0;
}
/*
int testExtractSpectrum(vector<double> values, vector<Extractor::cd> coefficients) {
	ExtractionDelegate delegate;
	delegate.fillHandlerMap();
	ExtractionDelegate::doCache = false;
	vector<Extractor::cd> res = delegate.extractSpectrum(values);
	for (int i = 0; i < res.size(); i++) {
		cout << "expected: (" << coefficients[i].real() << "," << coefficients[i].imag() << ") ";
		cout << "actual : (" << res[i].real() << "," << res[i].imag() << ")" << "\n";
	}

	return 0;
}*/