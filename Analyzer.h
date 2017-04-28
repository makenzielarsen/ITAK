//
// Created by Makenzie Larsen on 4/23/17.
//

#ifndef ITAK_ANALYZER_H
#define ITAK_ANALYZER_H

#include "AnalyzerStrategy.h"

class Analyzer {
private:
    AnalyzerStrategy* analyzerStrategy;
public:
    Analyzer(AnalyzerStrategy* analyzerStrategy);
    bool checkConfigurationValid();
    ResultSet* runAnalyzer(ifstream &inputStream);
};

#endif //ITAK_ANALYZER_H
