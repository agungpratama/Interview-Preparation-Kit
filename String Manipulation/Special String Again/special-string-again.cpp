#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long specialCount = 0;
    // vector<string> specialSub;

    for(long i = 0; i < n; i++) {
        string tmp_string(1, s[i]);

        //case for individual char
        // specialSub.push_back(tmp_string);
        specialCount++;

        if(s[i] != s[i-1]) {
            char diffChar = ' ';
            for (long j = 1; j <= i; j++) {
                if(s[i-j] == s[i+j] ) {
                    if(diffChar == ' ') {
                        //fill the diffChar allowed
                        diffChar = s[i-j];
                    }else if (diffChar != s[i-j] ) {
                        // to prevent the case like ababa 
                        break;
                    }
                    if(s[i-j] == diffChar) {
                        //case for all same char but except in the middle
                        
                        // string specialString = s.substr(i-j, 1 + 2*j ); 
                        // specialSub.push_back(specialString);
                        specialCount++;
                    }
                }else {
                    break;
                }
            }
        }else {
            for(long j = i -1; j >= 0; j--) {                
                if(s[i] != s[j]) {
                    break;
                }else {
                    //case for same char substring

                    // string specialString = s.substr(j, 1 + i-j);
                    // specialSub.push_back(specialString);
                    specialCount++;
                }
            }
        }


    }
    // //uncomment to see result of the specialsubstr list 
    // cout << endl << "specials subsstrings are:----------- " << endl;
    // for(auto &p: specialSub) {
    //     cout << p << endl;
    // }
    // cout << "------------------" << endl;
    // cout << endl << "results: " << specialCount << endl;
    cout << "result: " << specialCount << endl;
    return specialCount;
}


int main() {
    string input = "baabbabbbaaaabbbbaab";
    substrCount(input.size(), input);
    return 1;
}