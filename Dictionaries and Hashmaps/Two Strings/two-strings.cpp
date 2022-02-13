#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Link to the problem: https://www.hackerrank.com/challenges/two-strings/problem?isFullScreen=true

//since this problem doesn't even need us to return the substring, then we just need to check whether a char exists
string twoStrings(string s1, string s2) {
    map<char,bool> s1Map;

    for (auto &ch : s1) {  
        s1Map[ch] = true;
    }

    for(auto &ch : s2) {
        if(s1Map[ch]){
            return "YES";
        }
    }

    return "NO";
}

int main() {
    string s1 = "be";
    string s2 = "cat";
    cout << twoStrings(s1, s2);
    return 1;
}