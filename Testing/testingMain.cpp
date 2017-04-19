//
// Created by Makenzie Larsen on 4/7/17.
//

#include "ConfigurationTester.h"
#include "ResultSetTester.h"
#include "DenialOfServiceTester.h"
#include "PortScannerTester.h"

using namespace std;

int main(){
    cout << "Testing Configuration" << endl;
    ConfigurationTester configurationTester;
    configurationTester.testGetStringValue();
    configurationTester.testGetIntValue();
    configurationTester.testGetDoubleValue();
    cout << endl;

    cout << "Testing Result Set" << endl;
    ResultSetTester resultSetTester;
    resultSetTester.testGetResults();
    cout << endl;

    cout << "Testing Denial Of Service Analyzer" << endl;
    DenialOfServiceTester denialOfServiceTester;
    denialOfServiceTester.testConfigurationValid();
    denialOfServiceTester.testConstructor();
    denialOfServiceTester.testRun();
    cout << endl;

    cout << "Testing Port Scanner Analyzer" << endl;
    PortScannerTester portScannerTester;
    portScannerTester.testConfigurationValid();
    portScannerTester.testConstructor();
    portScannerTester.testRun();
    cout << endl;
}