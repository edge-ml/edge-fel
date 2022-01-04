#include "Extractor.h"
#include "ExtractionDelegate.h"
#include "ExtractionHandler.h"
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

	clock_t start, end;
	start = clock();
	map<string, double> results = delegate.extractAll(values);
	end = clock();
	cout << "time: " << ((double) end - start)/CLOCKS_PER_SEC << "\n";

	for (auto single : results) {
		cout << single.first << ": " << single.second << "\n";
	}

}


