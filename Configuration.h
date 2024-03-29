//
// Created by Makenzie Larsen on 4/13/17.
//

#ifndef ITAK_CONFIGURATION_H
#define ITAK_CONFIGURATION_H

#include <iostream>
#include <unordered_map>

using namespace std;

class Configuration {
private:
    unordered_map<string, string> configurationParameters;

public:
    string getStringValue(const string key);
    int getIntValue(const string key);
    double getDoubleValue(const string key);

    void set(const string key, const string value);
    void set(const string key, const int value);
    void set(const string key, const double value);

};

#endif //ITAK_CONFIGURATION_H
