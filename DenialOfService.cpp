//
// Created by Makenzie Larsen on 4/14/17.
//

#include "DenialOfService.h"
#include "Utils.h"
#include <vector>

using namespace std;

DenialOfServiceAnalyzer::DenialOfServiceAnalyzer(const Configuration &configuration) : Analyzer(configuration) {}


ResultSet* DenialOfServiceAnalyzer::run(ifstream &inputStream) {
    processData(inputStream);
    return analyzeData();

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
    vector<string> attackers;
    vector<string> possibleAttackers;
    vector<string> attackPeriods;

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
                attackers.push_back(srcAddress);
                attackPeriods.push_back(timeWindow);
            } else if (count >= possibleThreshold) {
                possibleAttackers.push_back(srcAddress);
                attackPeriods.push_back(timeWindow);
            }

        }
    }

    resultSet->set("Likely attackers", attackers);
    resultSet->set("Possible Attackers", possibleAttackers);
    resultSet->set("Attack Periods", attackPeriods);
    resultSet->set("Timeframe", { to_string(timeFrame) } );

    return resultSet;
}
