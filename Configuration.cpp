//
// Created by Makenzie Larsen on 4/14/17.
//

#include "Configuration.h"

// GETTERS

string Configuration::getStringValue(const string key) {
    return configurationParameters[key];
}

int Configuration::getIntValue(const string key) {
    auto val = getStringValue(key);
    return stoi(getStringValue(key));
}

double Configuration::getDoubleValue(const string key) {
    return stod(getStringValue(key));
}

// SETTERS

void Configuration::set(const string key, const string value) {
    configurationParameters[key] = value;
}

void Configuration::set(const string key, const int value) {
    configurationParameters[key] = to_string(value);
}

void Configuration::set(const string key, const double value) {
    configurationParameters[key] = to_string(value);
}
