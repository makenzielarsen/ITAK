//
// Created by Makenzie Larsen on 4/19/17.
//

#include "PortScannerTester.h"
#include "../Configuration.h"

void PortScannerTester::testConstructor() {
    Configuration configuration;
    configuration.set("Likely Port Attack Count", 40);
    configuration.set("Possible Port Attack Count", 30);
}

void PortScannerTester::testConfigurationValid() {

}

void PortScannerTester::testRun() {

}
