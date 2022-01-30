//#pragma once

#ifndef EXTRACTIONDELEGATE_H
#define EXTRACTIONDELEGATE_H

#include "ExtractionHandler.h"
#include "Extractor.h"
#include <map>
#include <string>
#include <vector>

namespace eh {
	class ExtractionHandler;
}

namespace ed {

	class ExtractionDelegate
	{
		
	public:
		//Constructor that fills the handler map
		ExtractionDelegate() {
			fillHandlerMap();
		}

		//Function pointer type
		typedef double (eh::ExtractionHandler::*handler_func) (std::string, std::vector<double>&);

		//Function pointer map
	    typedef std::map<std::string, handler_func> handler_map;
		handler_map handlers;

		//List of features that take parameters
		static std::vector<std::string> parameterFeatures;

		//Cache of calculated values
		static std::map<std::string, double> calculated;
		static bool doCache;
		static void checkAndInsert(std::string, double);

		//Extraction helpers
		double extractOne(std::string, std::vector<double>&, std::map<std::string, double>&);
		std::vector<double> extractOneVectorial(std::string, std::vector<double>&, std::map<std::string, double>&);
		std::map<std::string, double> extractSome(std::vector<std::string>&, std::vector<double>&, std::map<std::string, double>&);
		std::map<std::string, double> extractAll(std::vector <double>&, std::map<std::string, double>&);
		std::vector<co::cd> extractSpectrum(std::vector<double>&);

	private:
		void fillHandlerMap();
	};
	

}
#endif
