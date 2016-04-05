//============================================================================
// Name        : wzielin3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ConfigurationManager.h"
#include "HttpService.h"
#include "parser/HTMLParser.h"
#include "interpreter/HTMLInterpreter.h"
#include "filter/ModelsFilter.h"

int main(int argc, char** argv)
{
	try
	{
		ConfigurationManager configuration(argc, argv);

		HttpService http;
		std::string toParse = http.getHtml(configuration.webSiteUrl);

		HTMLElement root;
		HTMLParser parser(toParse, 0, &root);
		parser.parse();

		HTMLInterpreter interpreter(&root);
		std::vector<ResultModel*> allModels = interpreter.interpret();

		ModelsFilter filter(allModels);
		if(configuration.applyMalwareFilter)
		{
			filter.applyMalwareTypeFilter(configuration.malwareType);
		}
		if(configuration.applyThreatFilter)
		{
			filter.applyThreatTypeFilter((configuration.threaType));
		}

		std::vector<ResultModel*> filteredModels = filter.getModels();

		std::cout << "Finished";
	} catch (const char* e)
	{
		std::cout << e;
	}

	return 0;
}
