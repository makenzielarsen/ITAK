//
// Created by Makenzie Larsen on 4/14/17.
//
#include "PortScanner.h"

ResultSet* PortScannerAnalyzer::run(ifstream &inputStream) {
    ResultSet* resultSet = nullptr;
    long int timestamp;
    string srcAddress;
    string srcPort;
    string desPort;
    std::string line;
    getline(inputStream, line);
    if (line!="")
    {
        inputStream >> timestamp >> srcAddress >> srcPort >> desPort;
    }
    return resultSet;
}
