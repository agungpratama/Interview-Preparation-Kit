#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    map<int,int> frequencyMap; 
    map<int,int> frequencyFrequencyMap;

    vector<int> result;

    for(auto const& query:queries) {
        if(query[0] == 1) {
            if(frequencyMap[query[1]] > 0) {
                frequencyFrequencyMap[frequencyMap[query[1]]]--; // frequency before
            }
            frequencyMap[query[1]]++;
            frequencyFrequencyMap[frequencyMap[query[1]]]++; //frequency after
        }else if(query[0] == 2) {
            if(frequencyMap[query[1]] > 0){
                if( frequencyFrequencyMap[frequencyMap[query[1]]] > 0) {
                    frequencyFrequencyMap[frequencyMap[query[1]]]--; // frequency before
                }
                frequencyMap[query[1]]--;
                frequencyFrequencyMap[frequencyMap[query[1]]]++; //frequency after
            }
        }else if(query[0] == 3) {
            if(frequencyFrequencyMap[query[1]] > 0 ){
                result.push_back(1);
            }else {
                result.push_back(0);
            }
        }
    }

    //debug print
    // for(int i = 0; i < result.size(); i++) {
    //     cout << result[i] << endl;
    // }

    return result;
}

int main() {
    vector<vector<int>> input = {{1,3},{2,3},{3,2},{1,4},{1,5},{1,5},{1,4},{3,2},{2,4},{3,2}};
    freqQuery(input);
    return 0;
}