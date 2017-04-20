//
// Created by Makenzie Larsen on 4/19/17.
//

#include <iostream>
#include <fstream>
#include "PortScannerTester.h"
#include "Test.h"
#include "../Configuration.h"
#include "../PortScanner.h"

void PortScannerTester::testConstructor() {
    Configuration configuration;
    configuration.set("Likely Attack Port Count", 40);
    configuration.set("Possible Attack Port Count", 30);

    PortScannerAnalyzer denialOfServiceAnalyzer(configuration);
    denialOfServiceAnalyzer.checkConfigurationValid();
    ifstream testFile1;
    testFile1.open("OneSourceOneTimestampTest.csv");
    if (testFile1.is_open()) {
        ResultSet* resultSet = denialOfServiceAnalyzer.run(testFile1);
        TEST("open", "open");
    } else {
        TEST("closed", "open");
    }
}

void PortScannerTester::testConfigurationValid() {
    Configuration configuration;
    configuration.set("Likely Attack Port Count", 40);
    configuration.set("Possible Attack Port Count", 30);

    PortScannerAnalyzer portScannerAnalyzer(configuration);
    if (portScannerAnalyzer.checkConfigurationValid()) {
        TEST("true", "true");
    } else {
        TEST ("false", "true");
    }

    Configuration configuration1;
    configuration.set("Likely Attack Port Count", 40);

    PortScannerAnalyzer portScannerAnalyzer1(configuration1);
    if (!portScannerAnalyzer1.checkConfigurationValid()) {
        TEST("true", "false");
    } else {
        TEST("false", "false");
    }
}

void PortScannerTester::testRun() {
    Configuration configuration;
    configuration.set("Likely Attack Port Count", 40);
    configuration.set("Possible Attack Port Count", 30);
    configuration.set("Timeframe", 123);

    PortScannerAnalyzer portScannerAnalyzer(configuration);
    ifstream testFile1;
    testFile1.open("OneSourceOneTimestampTest.csv");
    if (testFile1.is_open()) {
        ResultSet* resultSet = portScannerAnalyzer.run(testFile1);
        unordered_map<string, vector<string>> set = resultSet->getResultSet();
        if (set.at("Likely attackers").size() == 1) {
            TEST("One attacker", "One attacker");
        } else {
            TEST("More than one attacker", "One attacker");
        }

        if (set.at("Possible Attackers").size() == 1) {
            TEST("One possible attacker", "One possible attacker");
        } else {
            TEST("More than one possible attacker", "One possible attacker");
        }
    } else {
        TEST("closed", "open");
    }
}
