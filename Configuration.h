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
    unordered_map<string, string> map;
public:
    string getStringValue(string key);
    int getIntValue(string key);
    double getDoubleValue(string key);

};

#endif //ITAK_CONFIGURATION_H
