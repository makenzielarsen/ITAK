//
// Created by Makenzie Larsen on 4/23/17.
//

#include "Analyzer.h"

Analyzer::Analyzer(AnalyzerStrategy analyzerStrategy) : analyzerStrategy(analyzerStrategy) {
}

bool Analyzer::checkConfigurationValid() {
    return analyzerStrategy.checkConfigurationValid();
}

ResultSet* Analyzer::runAnalyzer(ifstream &inputStream) {
    if (checkConfigurationValid()) {
        analyzerStrategy.processData(inputStream);
        return analyzerStrategy.analyzeData();
    }
    return nullptr;
}
