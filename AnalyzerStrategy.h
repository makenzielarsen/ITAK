//
// Created by Makenzie Larsen on 4/14/17.
//

#ifndef ITAK_ANALYZERSTRATEGY_H
#define ITAK_ANALYZERSTRATEGY_H

#include <iostream>
#include "ResultSet.h"
#include "Configuration.h"

using namespace std;

class AnalyzerStrategy {
protected:
    Configuration configuration;
public:
    AnalyzerStrategy(Configuration configuration);

    virtual bool checkConfigurationValid() = 0;
    virtual void processData(ifstream &inputStream) = 0;
    virtual ResultSet* analyzeData() = 0;

};

#endif //ITAK_ANALYZERSTRATEGY_H
