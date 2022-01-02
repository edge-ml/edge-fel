#include "Extractor.h"
#include "ExtractionDelegate.h"
#include "ExtractionHandler.h"
#include <vector>
#include <iostream>
using namespace eh;


using namespace ed;
using namespace std;
using namespace ex;

int main() {
	vector<double> values{ 5, 6, 3, 8, 5, 2, 3, 9, 1, 2, 6, 4, 3, 7, 5, 8, 6, 2, 2, 3 };

	Extractor e;
	double mean = e.mean(values);
	cout << "mean: " << mean << "\n";
	cout << "mean_abs_dev: " << e.mean_abs_dev(values, mean) << "\n";
	cout << "mean_geometric: " << e.mean_geometric(values) << "\n";
	cout << "median: " << e.median(values) << "\n";
	cout << "median_abs_diff: " << e.median_abs_diff(values) << "\n";
	cout << "median_diff: " << e.median_diff(values) << "\n";
	cout << "median_abs_dev: " << e.median_abs_dev(values, mean) << "\n";
	double var = e.var(values, mean);
	cout << "var: " << var << "\n";
	double std_dev = e.std_dev(values, var);
	cout << "std_dev: " << std_dev << "\n";
	cout << "avg_dev: " << e.avg_dev(values, mean) << "\n";
	cout << "abs_energy: " << e.abs_energy(values) << "\n";
	cout << "kurtosis: " << e.kurtosis(values, mean, std_dev) << "\n";
	cout << "skewness: " << e.skewness(values, mean, std_dev) << "\n";
	cout << "zero_cross: " << e.zero_cross(values) << "\n";
	cout << "VALUES: ";
	for (size_t i = 0; i < values.size(); i++) {
		cout << values[i] << " ";
	}
	cout << "\n";

	ExtractionDelegate delegate;

	delegate.fillHandlerMap();
	ExtractionDelegate::doCache = true;

	//cout << "mean: " << delegate.extractOne("mean", values) << "\n";

	map<string, double> results = delegate.extractAll(values);
	for (auto single : results) {
		cout << single.first << ": " << single.second << "\n";
	}

}