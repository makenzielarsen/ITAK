//
// Created by Makenzie Larsen on 4/14/17.
//
#include "PortScanner.h"
#include "Utils.h"

PortScannerAnalyzer::PortScannerAnalyzer(const Configuration &configuration) : Analyzer(configuration) {}

bool PortScannerAnalyzer::checkConfigurationValid() {
    string likelyAttack = configuration.getStringValue("Likely Attack Port Count");
    string possibleAttack = configuration.getStringValue("Possible Attack Port Count");
    return !(likelyAttack == " " || possibleAttack == " ");
}

ResultSet* PortScannerAnalyzer::run(ifstream &inputStream) {
    if (checkConfigurationValid()) {
        processData(inputStream);
        return analyze();
    }
    return nullptr;
}

void PortScannerAnalyzer::processData(ifstream &ifstream) {
    string line;
    while (getline(ifstream, line)) {
        string array[4];
        if(split(line, ',', array, 4)) {
            IPAddress srcAddress = array[1];
            int desPort = stoi(array[3]);

            try {
                addressToPorts[srcAddress].insert(desPort);
            } catch (out_of_range) {
                addressToPorts[srcAddress] = { desPort };
            }
        }
    }
}

ResultSet* PortScannerAnalyzer::analyze() {
    vector<string> attackers;
    vector<string> possibleAttackers;
    vector<string> portCount;
    vector<string> possiblePortCount;

    ResultSet* resultSet = new ResultSet;

    int likelyThreshold = configuration.getIntValue("Likely Attack Port Count");
    int possibleThreshold = configuration.getIntValue("Possible Attack Port Count");

    for (auto& x: addressToPorts) {
        string srcAddress = x.first;
        set<int> ports = x.second;
        if (ports.size() >= likelyThreshold) {
            attackers.push_back(srcAddress);
            portCount.push_back(to_string(ports.size()));
        } else if (ports.size() >= possibleThreshold) {
            possibleAttackers.push_back(srcAddress);
            possiblePortCount.push_back(to_string(ports.size()));
        }
    }

    resultSet->set("Likely attackers", attackers);
    resultSet->set("Possible Attackers", possibleAttackers);
    resultSet->set("Attacked Port Count", portCount);
    resultSet->set("Possible Attacked Port Count", possiblePortCount);
    return resultSet;
}
