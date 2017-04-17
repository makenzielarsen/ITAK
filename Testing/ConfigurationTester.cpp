//
// Created by Makenzie Larsen on 4/14/17.
//
#include "ConfigurationTester.h"
#include "../Configuration.h"
#include "Test.h"

void ConfigurationTester::testGetStringValue() {
    Configuration configuration;
    configuration.set("Timeframe", "time");
    string value = configuration.getStringValue("Timeframe");
    TEST(value, "time");
}

void ConfigurationTester::testGetIntValue() {
    Configuration configuration;
    configuration.set("Likely Attack Message Count", 2);
    int value = configuration.getIntValue("Likely Attack Message Count");
    TEST(value, 2);
}

void ConfigurationTester::testGetDoubleValue() {
    Configuration configuration;
    string test = to_string(5.5);
    configuration.set("Possible Attack Message Count", 5.5);
    double value = configuration.getDoubleValue("Possible Attack Message Count");
    TEST(value, 5.5);
}
