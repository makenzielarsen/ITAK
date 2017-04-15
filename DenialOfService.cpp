//
// Created by Makenzie Larsen on 4/14/17.
//

#include "DenialOfService.h"
#include <vector>

using namespace std;

void readIn() {

}

ResultSet* DenialOfServiceAnalyzer::run(ifstream &inputStream) {
    ResultSet* resultSet = nullptr;
    resultSet->resultSet.insert("Likely attackers", vector<string> attackers);
    return resultSet;
}
