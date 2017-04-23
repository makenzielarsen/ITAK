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

    PortScannerStrategy denialOfServiceAnalyzer(configuration);
    denialOfServiceAnalyzer.checkConfigurationValid();
    ifstream testFile1;
    testFile1.open("OneSourceOneTimestampTest.csv");
    if (testFile1.is_open()) {
        TEST("open", "open");
    } else {
        TEST("closed", "open");
    }
}

void PortScannerTester::testConfigurationValid() {
    Configuration configuration;
    configuration.set("Likely Attack Port Count", 40);
    configuration.set("Possible Attack Port Count", 30);

    PortScannerStrategy portScannerAnalyzer(configuration);
    if (portScannerAnalyzer.checkConfigurationValid()) {
        TEST("true", "true");
    } else {
        TEST ("false", "true");
    }

    Configuration configuration1;
    configuration.set("Likely Attack Port Count", 40);

    PortScannerStrategy portScannerAnalyzer1(configuration1);
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

    PortScannerStrategy portScannerAnalyzer(configuration);
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

    PortScannerStrategy Analyzer2(configuration);
    ifstream testFile2;
    testFile2.open("TenSources.csv");
    if (testFile2.is_open()) {
        ResultSet* resultSet = Analyzer2.run(testFile2);
        unordered_map<string, vector<string>> set = resultSet->getResultSet();
        if (set.at("Likely attackers").size() == 3) {
            TEST("Three attackers", "Three attackers");
        } else {
            TEST("More or less than three attackers", "Three attackers");
        }

        if (set.at("Possible Attackers").size() == 4) {
            TEST("Four possible attackers", "Four possible attackers");
        } else {
            TEST("More or less than four possible attackers", "Four possible attackers");
        }
    } else {
        TEST("closed", "open");
    }

}
