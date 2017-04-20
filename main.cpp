#include <iostream>
#include "Configuration.h"
#include "ResultSet.h"
#include "DenialOfService.h"
#include "PortScanner.h"

using namespace std;

void analyzerMenu(){
    cout << "A - Analyze file" << endl;
    cout << "X - Exit Analyzer" << endl;
}

Configuration getDOSConfiguration() {
    Configuration configuration;
    cout << "Enter the values you would like to apply for each of the following parameters" << endl;
    cout << "Enter a timeframe: ";
    string timeframe;
    cin >> timeframe;
    cout << "Enter the likely attack message count: ";
    string likely;
    cin >> likely;
    cout << "Enter the possible attack message count:";
    string possible;
    cin >> possible;
    configuration.set("Timeframe", timeframe);
    configuration.set("Likely Attack Message Count", likely);
    configuration.set("Possible Attack Message Count", possible);
}

void runResults(DenialOfServiceAnalyzer analyzer) {

}

void runDenialOfService() {
    cout << "---Welcome to the Denial Of Service Analyzer---" << endl;
    analyzerMenu();
    char choice;
    cin >> choice;
    while (choice != 'X'){
        switch (choice) {
            case 'A':
                Configuration configuration = getDOSConfiguration();
                DenialOfServiceAnalyzer analyzer(configuration);
                while (!analyzer.checkConfigurationValid()){
                    cout << "Invalid Configuration" << endl;
                    configuration = getDOSConfiguration();
                    DenialOfServiceAnalyzer analyzer(configuration);
                }
                runResults(analyzer);
                break;
            case 'X':
                continue;
            default:
                cout << "Unknown character" << endl;
        }
    }
}

void runPortScanner() {

}

void printAnalyzerMenu() {
    cout << "Currently supported Analyzers:" << endl;
    cout << "A - Denial of Service Analyzer" << endl;
    cout << "B - Port Scanner Analyzer" << endl;
    cout << "X - Exit program" << endl;
    cout << "Enter chosen Analyzer: ";
}

int main() {
    cout << "---Welcome to the ITAK system---" << endl;
    cout << endl;
    printAnalyzerMenu();
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
        printAnalyzerMenu();
    }
}