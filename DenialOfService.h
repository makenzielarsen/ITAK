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
#include "AnalyzerStrategy.h"
#include "ResultSet.h"

typedef string IPAddress;
typedef long int Timestamp;
typedef int Count;
typedef map<Timestamp, Count> Summary;

class DenialOfServiceStrategy : public AnalyzerStrategy {
private:
    unordered_map<IPAddress, Summary> addressToSummary;
public:
    DenialOfServiceStrategy(const Configuration &configuration);
    bool checkConfigurationValid();
    void processData(ifstream &ifstream);
    ResultSet *analyzeData();
};

#endif //ITAK_DENIALOFSERVICE_H
