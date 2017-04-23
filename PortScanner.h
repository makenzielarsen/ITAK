//
// Created by Makenzie Larsen on 4/14/17.
//

#ifndef ITAK_PORTSCANNER_H
#define ITAK_PORTSCANNER_H

#include <set>
#include "AnalyzerStrategy.h"

typedef string IPAddress;
typedef set<int> Ports;

class PortScannerStrategy : public AnalyzerStrategy {
private:
    unordered_map<IPAddress, Ports> addressToPorts;
public:
    PortScannerStrategy(const Configuration &configuration);
    bool checkConfigurationValid();
    void processData(ifstream &ifstream);
    ResultSet* analyze();
};

#endif //ITAK_PORTSCANNER_H
