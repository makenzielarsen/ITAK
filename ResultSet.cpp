//
// Created by Makenzie Larsen on 4/17/17.
//
#include "ResultSet.h"

void ResultSet::print(ofstream &) {

}

vector<string>& ResultSet::operator[](const string key) {
    return resultSet[key];
}