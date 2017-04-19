//
// Created by Makenzie Larsen on 4/17/17.
//
#include <iostream>
#include <iomanip>
#include "ResultSet.h"

void ResultSet::print(ostream &output) {
    for (auto& x : resultSet) {
        cout << x.first <<": ";
        cout << endl;
        for (auto& y : x.second) {
            cout << '\t' << '\t' << y << endl;
        }
    }
}

vector<string>& ResultSet::operator[](const string key) {
    return resultSet[key];
}

void ResultSet::set(const string key, const vector<string> values) {
    resultSet[key] = values;
}
