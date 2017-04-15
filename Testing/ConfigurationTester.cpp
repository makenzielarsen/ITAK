//
// Created by Makenzie Larsen on 4/14/17.
//
#include "ConfigurationTester.h"
#include "../Configuration.h"

void ConfigurationTester::testGetStringValue() {
    Configuration configuration;
    configuration.getStringValue("Timeframe");
}

void ConfigurationTester::testGetIntValue() {
    Configuration configuration;
    configuration.getIntValue("Likely Attack Message Count");
}

void ConfigurationTester::testGetDoubleValue() {
    Configuration configuration;
    configuration.getDoubleValue("Possible Attack Message Count");
}
