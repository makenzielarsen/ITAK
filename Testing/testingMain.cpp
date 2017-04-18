//
// Created by Makenzie Larsen on 4/7/17.
//

#include "ConfigurationTester.h"
#include "ResultSetTester.h"
#include "DenialOfServiceTester.h"

int main(){
    ConfigurationTester configurationTester;
    configurationTester.testGetStringValue();
    configurationTester.testGetIntValue();
    configurationTester.testGetDoubleValue();

    ResultSetTester resultSetTester;
    resultSetTester.testGetResults();

    DenialOfServiceTester denialOfServiceTester;
    denialOfServiceTester.testConstructor();
    denialOfServiceTester.testRun();
}