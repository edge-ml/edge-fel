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

	ExtractionDelegate delegate;
	delegate.fillHandlerMap();
	ExtractionDelegate::doCache = false;

	
	string caching = ExtractionDelegate::doCache ? "activated" : "not active";
	cout << "Starting feature extraction, caching " << caching << "\n";

	clock_t start, end;
	start = clock();
	map<string, double> results = delegate.extractAll(values);
	end = clock();

	for (auto single : results) {
		cout << single.first << ": " << single.second << "\n";
	}

	cout << "Feature extraction finished, took: " << ((double)end - start) / CLOCKS_PER_SEC << "\n";
}


