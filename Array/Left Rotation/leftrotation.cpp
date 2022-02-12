#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

//Link to the problem: https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem?isFullScreen=true
vector<int> rotLeft(vector<int> a, int d) {
    vector<int> result = {};
    int counter = 0;
    for (int i = 0; i < a.size(); i++) {
        if ((i + d) < a.size()) {
            result.push_back(a[d + i]);
            counter++;
        }else{
            result.push_back(a[i-counter]);
        }
    }

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return result;
}

int main() {
    vector<int> input = {1,2,3,4,5};
    rotLeft(input, 4);
    return 1;
}