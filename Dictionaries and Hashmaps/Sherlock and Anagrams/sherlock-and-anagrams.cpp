#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int sherlockAndAnagrams(string s) {
    int totalAnagram = 0;
    map<string,int> anagramCountMap;

    int stringSize = s.size();
    for(int i = 0; i < stringSize; i++) {
        cout << "i = " << i << endl;
            
        for(int j = 1; j <= stringSize - i; j++) {
            string currentSubString = s.substr(i, j);
            cout << "currentSubString = " << currentSubString << endl;
            sort(currentSubString.begin(), currentSubString.end());
            cout << "sortedSubstring = " << currentSubString << endl; 
            if (anagramCountMap.count(currentSubString)) {
                anagramCountMap[currentSubString]++;
            }else {
                anagramCountMap[currentSubString] = 1;
            }
        }
        cout << "next iteration i" << endl;
    }
    cout << endl << endl;
    cout << "combination characters occured: " << endl;
    for ( auto it = anagramCountMap.begin(); it != anagramCountMap.end(); ++it  ){
        cout << it->first << '\t' << it->second << endl;
        int anagramCountValue = it->second;
        totalAnagram += anagramCountValue*(anagramCountValue-1)/2;
    } 

    cout << "totalAnagram is: ";
    return totalAnagram;
}

int main() {
    string input = "kkkk";
    cout << sherlockAndAnagrams(input);
    return 1;
}