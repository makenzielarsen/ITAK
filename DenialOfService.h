//
// Created by Makenzie Larsen on 4/14/17.
//

#ifndef ITAK_DENIALOFSERVICE_H
#define ITAK_DENIALOFSERVICE_H

#include <iostream>
#include <istream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include "Analyzer.h"
#include "ResultSet.h"

class DenialOfServiceAnalyzer : Analyzer {
private:
    unordered_map<string, unordered_map<long int, int>> addressToSummary;
    unordered_map<long int, int> timestampToCount;
    Configuration configuration;
public:
    ResultSet* run(ifstream &inputStream);
};

#endif //ITAK_DENIALOFSERVICE_H
