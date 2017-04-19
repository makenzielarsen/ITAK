//
// Created by Makenzie Larsen on 4/19/17.
//

#include "PortScannerTester.h"
#include "Test.h"
#include "../Configuration.h"
#include "../PortScanner.h"

void PortScannerTester::testConstructor() {
    Configuration configuration;
    configuration.set("Likely Port Attack Count", 40);
    configuration.set("Possible Port Attack Count", 30);
}

void PortScannerTester::testConfigurationValid() {
    Configuration configuration;
    configuration.set("Likely Port Attack Count", 40);
    configuration.set("Possible Port Attack Count", 30);

    PortScannerAnalyzer portScannerAnalyzer(configuration);
    if (portScannerAnalyzer.checkConfigurationValid()) {
        TEST("true", "true");
    } else {
        TEST ("false", "true");
    }

    Configuration configuration1;
    configuration.set("Likely Port Attack Count", 40);

    PortScannerAnalyzer portScannerAnalyzer1(configuration1);
    if (!portScannerAnalyzer1.checkConfigurationValid()) {
        TEST("true", "false");
    } else {
        TEST("false", "false");
    }
}

void PortScannerTester::testRun() {

}
