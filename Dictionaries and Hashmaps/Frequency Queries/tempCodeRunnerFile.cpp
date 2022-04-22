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
        }else if(query[0] == 1) {
            if(frequencyMap[query[1]] > 0){
                if(frequencyFrequencyMap[frequencyMap[query[1]]] > 0) {
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
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    
    return result;