#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

//Link to the problem: https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

int hourglassSum(vector<vector<int>> arr) {

    vector<int> hourglassSumValues = {};


    //iterate the inner 2D array (subset of 5x5 2D array inside the original 6x6 2D array) 
    for(int i = 1; i < arr.size() - 1; i++) { //i for row index
        for(int j = 1; j < arr.size() - 1 ; j++) { //j for column index 
            //take the hourglass components:

            //take the top part of the hourglass components
            int topIndex = i - 1;
            int topPartSum = arr[topIndex][j-1] + arr[topIndex][j] + arr[topIndex][j+1];
            //take middle part of the hourglass
            int midSum = arr[i][j];
            
            //take the bottom part of the hourglass components
            int bottomIndex = i + 1;
            int bottomPartSum = arr[bottomIndex][j-1] + arr[bottomIndex][j] + arr[bottomIndex][j+1];

            int hourGlassSum = topPartSum + midSum + bottomPartSum;
            cout << "hourGlassSum:" << hourGlassSum << ", from: " << topPartSum << " + " << midSum << " + " << bottomPartSum << endl;
            hourglassSumValues.push_back(hourGlassSum);
        }
        cout << "\n";
    }

    int maxSum = INT_MIN;
    for(int i = 0; i < hourglassSumValues.size(); i++) {
        cout << hourglassSumValues[i] << " ";
        maxSum = max(maxSum, hourglassSumValues[i]);
    }
    cout << "\nResult is:" << maxSum << endl;
    return maxSum;
}

int main() {
    vector<vector<int>> input = {
        {-9,-9,-9, 1, 1, 1},
        { 0,-9, 0, 4, 3, 2},
        {-9,-9,-9, 1, 2, 3},
        { 0, 0, 8, 6 ,6, 0},
        { 0, 0, 0,-2, 0, 0},
        { 0, 0, 1, 2, 4, 0}
    };

    vector<vector<int>> input2 = {
        { 0,-4,-6, 0,-7,-6},
        {-1,-2,-6,-8,-3,-1},
        {-8,-4,-2,-8,-8,-6},
        {-3,-1,-2,-5,-7,-4},    
        {-3,-5,-3,-6,-6,-6},
        {-3,-6, 0,-8,-6,-7}
    };
    

    hourglassSum(input2);
    return 1;
}