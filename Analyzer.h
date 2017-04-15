//
// Created by Makenzie Larsen on 4/14/17.
//

#ifndef ITAK_ANALYZER_H
#define ITAK_ANALYZER_H

#include <iostream>
#include "ResultSet.h"

using namespace std;

class Analyzer {
private:

public:
    Analyzer();
    virtual ResultSet* run(ifstream &inputStream);
};

#endif //ITAK_ANALYZER_H
