//
// Created by Makenzie Larsen on 4/14/17.
//

#include "DenialOfService.h"
#include "Utils.h"
#include <vector>
#include <set>

using namespace std;

DenialOfServiceAnalyzer::DenialOfServiceAnalyzer(const Configuration &configuration) : Analyzer(configuration) {}


bool DenialOfServiceAnalyzer::checkConfigurationValid() {
    string timeframe = configuration.getStringValue("Timeframe");
    string likelyAttack = configuration.getStringValue("Likely Attack Message Count");
    string possibleAttack = configuration.getStringValue("Possible Attack Message Count");
    return !(timeframe == " " || likelyAttack == " " || possibleAttack == " ");
}

ResultSet* DenialOfServiceAnalyzer::run(ifstream &inputStream) {
    if (checkConfigurationValid()) {
        processData(inputStream);
        return analyzeData();
    }
    return nullptr;
}

void DenialOfServiceAnalyzer::processData(ifstream &ifstream) {
    string line;
    while (getline(ifstream, line)) {
        string array[4];
        if(split(line, ',', array, 4)) {
            Timestamp timestamp = stoi(array[0]);
            IPAddress srcAddress = array[1];

            try {
                Summary summary = addressToSummary[srcAddress];
                Count count = summary[timestamp];
                addressToSummary[srcAddress][timestamp] = count + 1;
            } catch (out_of_range) {
                addressToSummary[srcAddress][timestamp] = 1;
            }
        }
    }
}

ResultSet *DenialOfServiceAnalyzer::analyzeData() {
    set<string> attackers;
    set<string> possibleAttackers;
    set<string> attackPeriods;

    ResultSet* resultSet = new ResultSet();

    Timestamp timeFrame = configuration.getIntValue("Timeframe");
    int likelyThreshold = configuration.getIntValue("Likely Attack Message Count");
    int possibleThreshold = configuration.getIntValue("Possible Attack Message Count");


    for(auto& x: addressToSummary) {
        string srcAddress = x.first;
        Summary summary = x.second;
        for(auto& y: summary) {
            Timestamp timestamp = y.first; // s
            Count count = y.second; // c
            Timestamp startWindow = timestamp;
            Timestamp endWindow = startWindow + timeFrame;

            for(auto& z: summary) {
                if (z.first > startWindow && z.first < endWindow) {
                    count += z.second;
                }
            }

            string timeWindow = to_string(startWindow) + "-" + to_string(endWindow);

            if (count >= likelyThreshold) {
                attackers.insert(srcAddress);
                attackPeriods.insert(timeWindow);
            } else if (count >= possibleThreshold && attackers.find(srcAddress) == attackers.end()) {
                possibleAttackers.insert(srcAddress);
                attackPeriods.insert(timeWindow);
            }

        }
    }

    vector<string> attackersVector(attackers.begin(), attackers.end());
    vector<string> possibleAttackersVector(possibleAttackers.begin(), possibleAttackers.end());
    vector<string> attackPeriodsVector(attackPeriods.begin(), attackPeriods.end());

    resultSet->set("Likely attackers", attackersVector);
    resultSet->set("Possible Attackers", possibleAttackersVector);
    resultSet->set("Attack Periods", attackPeriodsVector);
    resultSet->set("Timeframe", { to_string(timeFrame) } );

    return resultSet;
}
