/*
 * testOutput.h
 *
 *  Created on: Nov 17, 2017
 *      Author: S. Miller
 */

#ifndef TESTOUTPUT_H_
#define TESTOUTPUT_H_

#include <sstream>
#include <ostream> //Just in case, since sstream should be inheriting this
#include <string>

void resultOut(const char* testName, const char* data, bool addQuotes, unsigned int result, unsigned int expected);
void resultOut(const char* testName, const char* data, bool addQuotes, int result, int expected);
void resultOut(const char* testName, const char* data, bool addQuotes, bool result, bool expected);
void resultOut(const char* testName, const char* data, bool addQuotes, std::ostringstream& result, const char* expected);

void doTestOnInt(const char* testName,const std::string& data, unsigned int expected, unsigned int(*f)(const unsigned int) );
void doTestOnInt(const char* testName,const std::string& data, int expected, int(*f)(const int));
void doTestOnInt(const char* testName,const std::string& data, const char* expected, void(*f)(std::ostream&,const unsigned int));

void doTestOnArray(const char* testName,const std::string& data, bool expected, bool(*f)(const int[],unsigned int) );

void doTestOnString(const char* testName,const char* data, bool expected, bool(*f)(std::string) );



#endif /* TESTOUTPUT_H_ */