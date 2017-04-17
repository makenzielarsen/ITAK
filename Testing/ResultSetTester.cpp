//
// Created by Makenzie Larsen on 4/17/17.
//

#include "ResultSetTester.h"
#include "../ResultSet.h"
#include "Test.h"

void ResultSetTester::testGetResults() {
    ResultSet resultSet;
    vector<string> expected = {"cat", "dog"};
    resultSet["Animals"] = expected;
    vector<string> actual = resultSet["Animals"];
    TEST(actual[0], expected[0]);
    TEST(actual[1], expected[1]);
}

