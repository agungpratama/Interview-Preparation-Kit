#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
//Link to the problem: https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> result = vector<long>(n,0);


    //do operations here
    //iterate the queries
    for(long i = 0; i < queries.size(); i++) {
        //do query
        long startIndex = queries[i][0] - 1;
        long endIndex = queries[i][1] - 1;
        long valueToAdd = queries[i][2];
        for(long j = startIndex; j <= endIndex; j++) {
            result[j] = result[j] + valueToAdd;
        }
    }

    //checking end results
    long biggestNumber = LONG_MIN;
    cout << "results: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
        biggestNumber = max(biggestNumber,result[i]);
    }
    cout << endl;
    return biggestNumber;
}

//SUM PREFIX METHOD
long arrayManipulation2(long n, vector<vector<long>> queries) {
    vector<long> sumPrefix = vector<long>(n,0);

    for(long i = 0; i < queries.size(); i++) {
        long startIndex = queries[i][0] - 1;
        long endIndex = queries[i][1] - 1;
        long valueToAdd = queries[i][2];
        sumPrefix[startIndex] += valueToAdd;
        if (endIndex + 1 < sumPrefix.size()) {
            sumPrefix[endIndex + 1] -= valueToAdd;
        }
    }

    //checking end results
    long biggestNumber = LONG_MIN;
    long sum = 0;
    cout << "results: ";
    for(long i = 0; i < sumPrefix.size(); i++) {
        //do the sum prefix opperation here
        sum = sum  + sumPrefix[i];
        biggestNumber = max(biggestNumber,sum);
    }
    cout << endl;
    return biggestNumber;
}


int main() {
    vector<vector<long>> queries = {
        {1,2,100},
        {2,5,100},
        {3,4,100},
    };

    cout << arrayManipulation2(5, queries);
    return 1;
}