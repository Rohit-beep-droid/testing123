/*
 * testOutput.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: S. Miller
 */

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include "testOutput.h"


void resultOut(const char* testName, const char* data, bool addQuotes, unsigned int result, unsigned int expected) {
    std::cout << testName << "(" << (addQuotes ? "\"" : "") << data << (addQuotes ? "\"" : "") << ") = "
              << result
              << "\t"
              << (result == expected ? "Pass" : "Fail")
              << std::endl;
}

void resultOut(const char* testName, const char* data, bool addQuotes, int result, int expected) {
    std::cout << testName << "(" << (addQuotes ? "\"" : "") << data << (addQuotes ? "\"" : "") << ") = "
              << result
              << "\t"
              << (result == expected ? "Pass" : "Fail")
              << std::endl;
}

void resultOut(const char* testName, const char* data, bool addQuotes, bool result, bool expected) {
    std::cout << testName << "(" << (addQuotes ? "\"" : "") << data << (addQuotes ? "\"" : "") << ") = "
              << (result ? "True" : "False")
              << "\t"
              << (result == expected ? "Pass" : "Fail")
              << std::endl;
}

void resultOut(const char* testName, const char* data, bool addQuotes, std::ostringstream& result, const char* expected) {
    std::cout << testName << "(" << (addQuotes ? "\"" : "") << data << (addQuotes ? "\"" : "") << ") = "
              << result.str()
              << "\t"
              << (result.str() == expected ? "Pass" : "Fail")
              << std::endl;
}

void doTestOnInt(const char* testName,const std::string& data, unsigned int expected, unsigned int(*f)(const unsigned int) ) {
    std::istringstream ssin(data);
    int n;
    ssin >> n;
    resultOut(testName,data.c_str(),false,f(n),expected);
}

void doTestOnInt(const char* testName,const std::string& data, int expected, int(*f)(const int) ) {
    std::istringstream ssin(data);
    int n;
    ssin >> n;
    resultOut(testName,data.c_str(),false,f(n),expected);
}

void doTestOnInt(const char* testName,const std::string& data, const char* expected, void(*f)(std::ostream& stream,const unsigned int) ) {
    std::istringstream ssin(data);
    std::ostringstream ssout;
    int n;
    ssin >> n;
    f(ssout,n);
    resultOut(testName,data.c_str(),false,ssout,expected);
}

void doTestOnArray(const char* testName,const std::string& data, bool expected, bool(*f)(const int[],unsigned int) ) {
    //Must construct array first
    std::istringstream ssin(data.substr(1,data.length()-2));
    int index = 0;
    int arrayLength = count(data.begin(), data.end(), ',') + 1;
    int* arrayData = new int[arrayLength];
    while ( !ssin.fail() ) {
        if ( isdigit(ssin.peek())  ) {
            ssin >> arrayData[index];
            ++index;
        } else {
            ssin.ignore(1);
        }
    }

    resultOut(testName,data.c_str(),false,f(arrayData,arrayLength),expected);
    delete [] arrayData;
}

void doTestOnString(const char* testName,const char* data, bool expected, bool(*f)(std::string) ) {

    resultOut(testName,data,true,f(data),expected);

}

