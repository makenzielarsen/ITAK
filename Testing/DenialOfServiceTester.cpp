//
// Created by Makenzie Larsen on 4/17/17.
//

#include <iostream>
#include "DenialOfServiceTester.h"
#include "../DenialOfService.h"
#include "Test.h"

void DenialOfServiceTester::testConstructor() {
    Configuration configuration;
    configuration.set("Likely Attack Message Count", 40);
    configuration.set("Possible Attack Message Count", 30);
    configuration.set("Timeframe", 123);

    DenialOfServiceAnalyzer denialOfServiceAnalyzer(configuration);
    ifstream testFile1;
    testFile1.open("OneSourceOneTimestampTest.csv");
    if (testFile1.is_open()) {
        TEST("open", "open");
    } else {
        TEST("closed", "open");
    }
}

void DenialOfServiceTester::testConfigurationValid() {
    Configuration configuration;
    configuration.set("Likely Attack Message Count", 40);
    configuration.set("Possible Attack Message Count", 30);
    configuration.set("Timeframe", 123);

    DenialOfServiceAnalyzer denialOfServiceAnalyzer(configuration);
    if (denialOfServiceAnalyzer.checkConfigurationValid()) {
        TEST("true", "true");
    } else {
        TEST("false", "true");
    }

    Configuration failedConfiguration;
    failedConfiguration.set("Likely Attack Message Count", 70);
    failedConfiguration.set("Possible Attack Message Count", 45);

    DenialOfServiceAnalyzer failedAnalyzer(failedConfiguration);
    if (failedAnalyzer.checkConfigurationValid()) {
        TEST("false", "false");
    } else {
        TEST("true", "false");
    }
}

void DenialOfServiceTester::testRun() {
    Configuration configuration;
    configuration.set("Likely Attack Message Count", 40);
    configuration.set("Possible Attack Message Count", 30);
    configuration.set("Timeframe", 123);

    DenialOfServiceAnalyzer denialOfServiceAnalyzer(configuration);
    ifstream testFile1;
    testFile1.open("OneSourceOneTimestampTest.csv");
    if (testFile1.is_open()) {
        ResultSet* resultSet = denialOfServiceAnalyzer.run(testFile1);
        unordered_map<string, vector<string>> set = resultSet->getResultSet();
        TEST(set["Likely attackers"].size(), 1);
        TEST(set["Possible Attackers"].size(), 1);
    } else {
        TEST("closed", "open");
    }

    ifstream testFile2;
    testFile2.open("TenSources.csv");
    if (testFile2.is_open()) {
        ResultSet* resultSet = denialOfServiceAnalyzer.run(testFile2);
        unordered_map<string, vector<string>> set = resultSet->getResultSet();
        TEST(set["Likely attackers"].size(), 4);
        TEST(set["Possible Attackers"].size(), 3);
    } else {
        TEST("closed", "open");
    }
}
