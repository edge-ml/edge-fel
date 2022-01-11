//#pragma once

#ifndef EXTRACTIONDELEGATE_H
#define EXTRACTIONDELEGATE_H

#include "ExtractionHandler.h"
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
		//Function pointer type
		typedef double (eh::ExtractionHandler::*handler_func) (std::string, std::vector<double>&);

		//Function pointer map
	    typedef std::map<std::string, handler_func> handler_map;
		static handler_map handlers;
		void fillHandlerMap();

		//Cache of calculated values
		static std::map<std::string, double> calculated;
		static bool doCache;
		static void checkAndInsert(std::string, double);

		//Extraction helpers
		double extractOne(std::string, std::vector<double>&);
		std::vector<double> extractSome(std::vector<std::string>&, std::vector<double>&);
		std::map<std::string, double> extractAll(std::vector <double>&);

	};

}
#endif
