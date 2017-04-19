//
// Created by Makenzie Larsen on 4/14/17.
//

#ifndef ITAK_PORTSCANNER_H
#define ITAK_PORTSCANNER_H

#include "Analyzer.h"

typedef string IPAddress;
typedef int Port;
typedef vector<Port> Ports;
typedef unordered_map<IPAddress, Ports> Summary;

class PortScannerAnalyzer : Analyzer {
private:
    unordered_map<IPAddress, Ports> addressToPorts;
    void processData(ifstream &ifstream);
    ResultSet* analyze();
public:
    PortScannerAnalyzer(const Configuration &configuration);
    bool checkConfigurationValid();
    ResultSet* run(ifstream &inputStream);
};

#endif //ITAK_PORTSCANNER_H
