#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int commonChild(string s1, string s2) {
    int rowLength = s1.length() + 1;
    int colLength = s2.length() + 1;
  

    vector<vector<int>> matrix;

    for(int i = 0; i < colLength; i++) {
        vector<int> subMatrix = vector<int>();
        for(int j = 0; j < rowLength; j++) {            
            subMatrix.push_back(0);
        }
        matrix.push_back(subMatrix);
    }
    

    for(int i = 0; i < colLength - 1; i++) {
        vector<int> subMatrix = matrix.at(i);
        for(int j = 0; j < rowLength - 1; j++) {            
            // cout << "s1[i] == s2[j]" << s1[i] << " == " << s2[j] << endl;
            if (s1[i] == s2[j]) {
                matrix.at(i+1).at(j+1) = matrix.at(i).at(j) + 1;
            } else {
                 matrix.at(i+1).at(j+1) = max(matrix.at(i+1).at(j), matrix.at(i).at(j+1));
            }
        }
    }


    // //Debug / display matrix
    // cout << "_|";
    // for(int j=0; j < s1.length(); j++) {
    //     cout << s1[j] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < matrix.size(); ++i)
    // {   
    //     cout << s2[i] << "|";
    //     vector<int> subMatrix = matrix.at(i);
    //      for (int j = 0; j < subMatrix.size(); ++j) {
    //         cout << subMatrix.at(j) << "," ;
    //      }
    //      cout << endl;
    // }
    // cout << "Result:" << matrix.at(s2.length()).at(s1.length()) << endl;
    return matrix.at(s2.length()).at(s1.length());
}

int main() {
    commonChild("SHINCHAN", "NOHARAAA");
    return 1;
}