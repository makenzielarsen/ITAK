//
// Created by Makenzie Larsen on 4/21/17.
//

#ifndef ITAK_USERINTERFACE_H
#define ITAK_USERINTERFACE_H

#include <iostream>
#include "Configuration.h"
#include "ResultSet.h"
#include "DenialOfService.h"
#include "PortScanner.h"

using namespace std;

class UserInterface {
private:
    void printAnalyzerMenu();
    void analyzerMenu();
    void runPortScanner();
    void runDenialOfService();
    Configuration getPSConfiguration();
    Configuration getDOSConfiguration();
    void runResults(PortScannerAnalyzer analyzer);
    void runResults(DenialOfServiceAnalyzer analyzer);

public:
    void run();
};

#endif //ITAK_USERINTERFACE_H
