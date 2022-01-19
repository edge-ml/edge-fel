#ifndef EXTRACTIONTEST_H
#define EXTRACTIONTEST_H

#include "FeatureExtractionNew.ino/Extractor.h"
#include "FeatureExtractionNew.ino/ExtractionDelegate.h"
#include "FeatureExtractionNew.ino/ExtractionHandler.h"
#include "Data.h"
#include <vector>
#include <iostream>
#include <limits>

int testExtractOne(std::vector<double>, std::map<std::string, double>);

int testExtractSome(std::vector<double>, std::map<std::string, double>);

int testExtractAll(std::vector<double>, std::map<std::string, double>);

//int testExtractSpectrum(std::vector<double>, std::vector<ex::Extractor::cd>);


#endif
