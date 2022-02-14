#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Link to the problem: https://www.hackerrank.com/challenges/count-triplets-1/problem

long countTriplets(vector<long> arr, long r) {
    map<int,long> secondNumTable, thirdNumTable;

    long tripletsCount = 0;
    for (int i = 0; i < arr.size(); i++) {
        if(thirdNumTable.find(arr[i]) != thirdNumTable.end()) {
            tripletsCount = tripletsCount +thirdNumTable[arr[i]];
        }

        if(secondNumTable.find(arr[i]) != secondNumTable.end()) {
            thirdNumTable[arr[i] * r] += secondNumTable[arr[i]];
        }

        secondNumTable[arr[i] * r]++;

    }

    cout << "Result: " << tripletsCount << endl;
    return tripletsCount; 
}

int main() {
    vector<long> input = {1,3,9,9,27,81}; 
    countTriplets(input, 3);

    // vector<long> input2 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    // countTriplets(input2,1);

    // vector<long> input = {1,1,1,1}; 
    // countTriplets(input, 1);

    return 1;
}