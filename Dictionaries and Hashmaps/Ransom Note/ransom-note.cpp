#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Link to the problem: https://www.hackerrank.com/challenges/ctci-ransom-note/problem?isFullScreen=true

void checkMagazine(vector<string> magazine, vector<string> note) {
    //populate words available from magazine, make it as integer to handle repeating words
    map<string,int> mapWordAvailable;
    for(int i = 0; i < magazine.size(); i++) {
        mapWordAvailable[magazine[i]]++;
    }

    for(int i = 0; i < note.size(); i++) {
        if(mapWordAvailable[note[i]] < 1) {
            cout << "No";
            return;
        }else {
            //change the words available to false since it's already taken from current need.
            mapWordAvailable[note[i]]--;
        }
    }
    cout << "Yes";
}


int main() {
    vector<string> magazine = {"give","me","one","grand","today","night"};
    vector<string> note = {"give","one","grand","today"};
    checkMagazine(magazine, note);
    return 0;
}