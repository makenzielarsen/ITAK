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
        TEST("open", "open");
    } else {
        TEST("closed", "open");
    }
}
