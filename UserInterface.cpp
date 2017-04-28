//
// Created by Makenzie Larsen on 4/21/17.
//
#include <iostream>
#include "Configuration.h"
#include "ResultSet.h"
#include "Analyzer.h"
#include "DenialOfService.h"
#include "PortScanner.h"
#include "UserInterface.h"

void UserInterface::printAnalyzerMenu() {
    cout << "A - Analyze file" << endl;
    cout << "X - Exit Analyzer" << endl;
}

void UserInterface::runResults(Analyzer* analyzer) {
    cout << "Enter the file path you want analyzed: ";
    string fileName;
    cin >> fileName;
    ifstream inputFile;
    inputFile.open(fileName);
    if (inputFile.is_open()) {
        ResultSet* resultSet = analyzer->runAnalyzer(inputFile);
        cout << "Data Analyzed." << endl;
        inputFile.close();
        resultSet->print(cout);
    } else {
        cout << "File not opened." << endl;
        runResults(analyzer);
    }
}

Configuration UserInterface::getDOSConfiguration() {
    Configuration configuration;
    cout << "Enter the values you would like to apply for each of the following parameters" << endl;
    cout << "Timeframe: ";
    string timeframe;
    cin >> timeframe;
    cout << "Likely attack message count: ";
    string likely;
    cin >> likely;
    cout << "Possible attack message count: ";
    string possible;
    cin >> possible;
    configuration.set("Timeframe", timeframe);
    configuration.set("Likely Attack Message Count", likely);
    configuration.set("Possible Attack Message Count", possible);
    return configuration;
}

Configuration UserInterface::getPSConfiguration() {
    Configuration configuration;
    cout << "Enter the values you would like to apply for each of the following parameters" << endl;
    cout << "Likely Attack Port Count: ";
    string likely;
    cin >> likely;
    cout << "Possible Attack Port Count: ";
    string possible;
    cin >> possible;
    configuration.set("Likely Attack Port Count", likely);
    configuration.set("Possible Attack Port Count", possible);
    return configuration;
}

void UserInterface::runDenialOfService() {
    Configuration configuration = getDOSConfiguration();
    DenialOfServiceStrategy* strategy = new DenialOfServiceStrategy(configuration);
    Analyzer analyzer(strategy);

    cout << "---Welcome to the Denial Of Service Analyzer---" << endl;
    printAnalyzerMenu();

    char choice;
    cin >> choice;
    while (choice != 'X'){
        switch (choice) {
            case 'A':
                if (strategy->checkConfigurationValid()) {
                    runResults(&analyzer);
                } else {
                    cout << "Invalid Configuration" << endl;
                }
                break;
            case 'X':
                continue;
            default:
                cout << "Unknown character" << endl;
                break;
        }
        if (strategy->checkConfigurationValid()) {
            printAnalyzerMenu();
            cin >> choice;
        } else {
            choice = 'X';
        }
    }
}

void UserInterface::runPortScanner() {
    Configuration configuration;
    configuration = getPSConfiguration();
    PortScannerStrategy* strategy = new PortScannerStrategy(configuration);
    Analyzer analyzer(strategy);

    cout << "--- Welcome to the Port Scanner Analyzer ---" << endl;
    printAnalyzerMenu();
    char choice;
    cin >> choice;
    while (choice != 'X') {
        switch (choice) {
            case 'A':
                if (strategy->checkConfigurationValid()){
                    runResults(&analyzer);
                } else {
                    cout << "Invalid Configuration" << endl;
                }
                break;
            case 'X':
                continue;
            default:
                cout << "Unknown character" << endl;
                break;
        }
        if (strategy->checkConfigurationValid()) {
            printAnalyzerMenu();
            cin >> choice;
        } else {
            choice = 'X';
        }
    }
}

void UserInterface::printUIMenu() {
    cout << "Currently supported Analyzers:" << endl;
    cout << "A - Denial of Service Analyzer" << endl;
    cout << "B - Port Scanner Analyzer" << endl;
    cout << "X - Exit program" << endl;
    cout << "Enter chosen Analyzer: ";
}

void UserInterface::run() {
    cout << "---Welcome to the ITAK system---" << endl;
    cout << endl;
    printUIMenu();
    char choice;
    cin >> choice;
    while (choice != 'X') {
        switch (choice) {
            case 'A':
                runDenialOfService();
                break;
            case 'B':
                runPortScanner();
                break;
            case 'X':
                continue;
            default:
                cout << "Unknown character." << endl;
        }
        printUIMenu();
        cin >> choice;
    }
}
