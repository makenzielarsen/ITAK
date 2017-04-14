//
// Created by Makenzie Larsen on 4/14/17.
//

#include "Configuration.h"

string Configuration::getStringValue(string key) {
    string value = map.find(key);
    return value;
}

int Configuration::getIntValue(string key) {
    string value = getStringValue(key);
    return stoi(value);
}

double Configuration::getDoubleValue(string key) {
    string value = getStringValue(key);
    return stod(key);
}
