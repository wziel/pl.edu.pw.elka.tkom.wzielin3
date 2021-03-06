/*
 * ConfigurationManager.h
 *
 *  Created on: Apr 4, 2016
 *      Author: wojciech
 */

#ifndef CONFIGURATIONMANAGER_H_
#define CONFIGURATIONMANAGER_H_

#include<iostream>
#include<map>
#include<string.h>
#include"../interpreter/ResultModel.h"

/**
 * Class representing configuration of currently run program.
 */
class ConfigurationManager
{
public:
	/**
	 * Default constructor.
	 * @param argc command line arguments count
	 * @param argv command line arguments
	 */
	ConfigurationManager(int argc, char** argv);
	virtual ~ConfigurationManager();

	/**Specifies which interpreter should be used. if true details interpreter is used.*/
	bool single = false;
	bool readFromFile = false;
	bool applyMalwareFilter;
	bool applyThreatFilter;
	std::string malwareType;
	std::string threaType;
	std::string path;
private:

	/**
	 * Sets filtering by malware type configuration.
	 * @param argv malware filter argv argument received in command line
	 */
	void ConfigureMalwareFilter(std::string argv);

	/**
	 * Sets filtering by threat type configuration.
	 * @param argv threat filter argv argument received in command line
	 */
	void ConfigureThreatFilter(std::string argv);
};

#endif /* CONFIGURATIONMANAGER_H_ */
