//
// Created by Makenzie Larsen on 4/17/17.
//

#include "DenialOfServiceTester.h"
#include "../DenialOfService.h"
#include "Test.h"

void DenialOfServiceTester::testConstructor() {
    Configuration configuration;
    configuration.set("Likely Attack Message Count", 40);
    configuration.set("Possible Attacker Message Count", 30);
    configuration.set("Timeframe", 123);

    DenialOfServiceAnalyzer denialOfServiceAnalyzer(configuration);
    ifstream testFile1;
    testFile1.open("OneSourceOneTimestampTest.csv");
    if (testFile1.is_open()) {
        ResultSet* resultSet = denialOfServiceAnalyzer.run(testFile1);
        resultSet->print(cout);
    } else {
        TEST("closed", "open");
    }
}

void DenialOfServiceTester::testConfigurationValid() {
    Configuration configuration;
    configuration.set("Likely Attack Message Count", 40);
    configuration.set("Possible Attacker Message Count", 30);
    configuration.set("Timeframe", 123);

    DenialOfServiceAnalyzer denialOfServiceAnalyzer(configuration);
    if (denialOfServiceAnalyzer.checkConfigurationValid()) {
        TEST("true", "true");
    } else {
        TEST("false", "true");
    }

    Configuration configuration1;
    configuration1.set("Likely Attack Message Count", 40);
    configuration1.set("Possible Attacker Message Count", 30);

    DenialOfServiceAnalyzer denialOfServiceAnalyzer1(configuration1);
    if (!denialOfServiceAnalyzer1.checkConfigurationValid()) {
        TEST("false", "false");
    } else {
        TEST("true", "false");
    }
}

void DenialOfServiceTester::testRun() {
    Configuration configuration;
    configuration.set("Likely Attack Message Count", 40);
    configuration.set("Possible Attacker Message Count", 30);
    configuration.set("Timeframe", 123);

    DenialOfServiceAnalyzer denialOfServiceAnalyzer(configuration);
    ifstream testFile1;
    testFile1.open("OneSourceOneTimestampTest.csv");
    if (testFile1.is_open()) {
        ResultSet* resultSet = denialOfServiceAnalyzer.run(testFile1);
        resultSet->print(cout);

    } else {
        TEST("closed", "open");
    }
}
