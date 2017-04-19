//
// Created by Makenzie Larsen on 4/14/17.
//

#ifndef ITAK_DENIALOFSERVICE_H
#define ITAK_DENIALOFSERVICE_H

#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <map>
#include "Analyzer.h"
#include "ResultSet.h"

typedef string IPAddress;
typedef long int Timestamp;
typedef int Count;
typedef map<Timestamp, Count> Summary;

class DenialOfServiceAnalyzer : Analyzer {
private:
    unordered_map<IPAddress, Summary> addressToSummary;
    void processData(ifstream &ifstream);
    ResultSet *analyzeData();
public:
    DenialOfServiceAnalyzer(const Configuration &configuration);
    bool checkConfigurationValid();
    ResultSet* run(ifstream &inputStream);
};

#endif //ITAK_DENIALOFSERVICE_H
