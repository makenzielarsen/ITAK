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
    
    virtual bool checkConfigurationValid();
    virtual void processData(ifstream &inputStream);
    virtual ResultSet* analyzeData();
    
    ResultSet* run(ifstream &inputStream);
};

#endif //ITAK_ANALYZERSTRATEGY_H