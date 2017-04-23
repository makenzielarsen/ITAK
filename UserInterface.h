//
// Created by Makenzie Larsen on 4/21/17.
//

#ifndef ITAK_USERINTERFACE_H
#define ITAK_USERINTERFACE_H

#include <iostream>
#include "Configuration.h"
#include "ResultSet.h"
#include "Analyzer.h"

using namespace std;

class UserInterface {
private:
    void printUIMenu();
    void printAnalyzerMenu();
    void runPortScanner();
    void runDenialOfService();
    Configuration getPSConfiguration();
    Configuration getDOSConfiguration();
    void UserInterface::runResults(Analyzer analyzer);

public:
    void run();
};

#endif //ITAK_USERINTERFACE_H
