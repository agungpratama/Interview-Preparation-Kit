#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;


int makeAnagram(string a, string b) {
    
    map<char,int> aCountCharMap;

    int deletedNeeded = 0;

    for (int i = 0; i < a.size(); i++){
        cout << a[i];
        aCountCharMap[a[i]]++;
    }

    cout << "" << endl;
    
    for (int i = 0; i < b.size(); i++){
        cout << b[i];
        aCountCharMap[b[i]]--;
    }


    for ( const auto &p : aCountCharMap )
    {
        std::cout << p.first << '\t' << p.second << std::endl;
        deletedNeeded = deletedNeeded + abs(p.second);
    } 

    
    cout << "" << endl;
    cout << "Deleted Needed: " << deletedNeeded << endl;

    return deletedNeeded;
}


int main() {
    makeAnagram("cde", "def");
    return 1;
}