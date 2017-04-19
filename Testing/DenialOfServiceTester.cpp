//
// Created by Makenzie Larsen on 4/17/17.
//

#include "DenialOfServiceTester.h"
#include "../DenialOfService.h"
#include "Test.h"

void DenialOfServiceTester::testConstructor() {
    Configuration configuration;
    configuration.set("Likely attacks", 0);
    configuration.set("Possible attackers", 0);
    configuration.set("Attack Periods", 0);
    configuration.set("Timeframe", 0);

    DenialOfServiceAnalyzer denialOfServiceAnalyzer(configuration);
    ifstream testFile1;
    testFile1.open("testConstructor.csv");
    if (testFile1.is_open()) {
        ResultSet* resultSet = denialOfServiceAnalyzer.run(testFile1);
        resultSet->print(cout);
    } else {
        TEST("closed", "open");
    }
}

void DenialOfServiceTester::testConfigurationValid() {

}

void DenialOfServiceTester::testRun() {
    Configuration configuration;
    configuration.set("Likely attacks", 0);
    configuration.set("Possible attackers", 0);
    configuration.set("Attack Periods", 0);
    configuration.set("Timeframe", 0);

    DenialOfServiceAnalyzer denialOfServiceAnalyzer(configuration);
    ifstream testFile1;
    testFile1.open("testConstructor.csv");
    if (testFile1.is_open()) {
        ResultSet* resultSet = denialOfServiceAnalyzer.run(testFile1);
        resultSet->print(cout);

    } else {
        TEST("closed", "open");
    }
}
