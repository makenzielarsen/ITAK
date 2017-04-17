//
// Created by Makenzie Larsen on 4/14/17.
//

#ifndef ITAK_RESULTSET_H
#define ITAK_RESULTSET_H

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class ResultSet {
private:
    unordered_map<string, vector<string>> resultSet;
public:
    void print(ofstream &outputStream);
    vector<string>& operator[] (const string key);
};

#endif //ITAK_RESULTSET_H
