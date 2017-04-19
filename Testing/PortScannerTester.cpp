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
    ifstream testFile1;
    testFile1.open("OneSourceOneTimestampTest.csv");
    if (testFile1.is_open()) {
        ResultSet* resultSet = denialOfServiceAnalyzer.run(testFile1);
        resultSet->print(cout);
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
        resultSet->print(cout);

    } else {
        TEST("closed", "open");
    }
}
