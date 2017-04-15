//
// Created by Makenzie Larsen on 4/14/17.
//

#ifndef ITAK_PORTSCANNER_H
#define ITAK_PORTSCANNER_H

#include "Analyzer.h"

class PortScannerAnalyzer : Analyzer {
private:

public:
    ResultSet* run(ifstream &inputStream);
};

#endif //ITAK_PORTSCANNER_H
