//
// Created by Makenzie Larsen on 4/14/17.
//
#include "AnalyzerStrategy.h"

AnalyzerStrategy::AnalyzerStrategy(Configuration configuration) : configuration(configuration) {
}

bool AnalyzerStrategy::checkConfigurationValid() {
    return false;
}

void AnalyzerStrategy::processData(ifstream &inputStream) {
    return;
}

ResultSet* AnalyzerStrategy::analyzeData() {
    ResultSet* resultSet = nullptr;
    return resultSet;
}

ResultSet* AnalyzerStrategy::run(ifstream &inputStream) {
    if (checkConfigurationValid()) {
        processData(inputStream);
        return analyzeData();
    }
    return nullptr;
}
