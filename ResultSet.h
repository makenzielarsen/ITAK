//
// Created by Makenzie Larsen on 4/14/17.
//

#ifndef ITAK_RESULTSET_H
#define ITAK_RESULTSET_H

#include <unordered_map>
#include <vector>

using namespace std;

class ResultSet {
private:

public:
    unordered_map<string, vector<string>> resultSet;
    void print(ofstream &);
};

#endif //ITAK_RESULTSET_H
