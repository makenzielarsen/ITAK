#include <iostream>
#include "ResultSet.h"

using namespace std;

int main() {
    ResultSet resultSet;
    vector<string> animals = {"cat", "dog", "bird", "pig", "cow"};
    resultSet.set("Animals", animals);
    resultSet.print(cout);

}