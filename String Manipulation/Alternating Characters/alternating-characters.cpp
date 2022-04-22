#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int alternatingCharacters(string s) {
    char currChar = ' '; 
    int deletionCount = 0;
    for (int i = 0; i < s.size(); i++){
        cout << s[i];      
        if (currChar != s[i]) {
            currChar = s[i];
            
        }else {
            deletionCount++;
        }
    }

    cout << "Deletion count: " << deletionCount << endl;
    return deletionCount;

}

int main() {
    alternatingCharacters("AAABBB");
    return 1;
}