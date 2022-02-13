#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

//Link to the problem:https://www.hackerrank.com/challenges/minimum-swaps-2/problem?isFullScreen

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int swapsCount = 0;
    for (int i = 0; i < arr.size(); i++) {
        //do swaps if necessary
        cout << arr[i] << " checking ..." << endl;
        if(arr[i] != (i+1) ) {
            //needs to do swap
            int value = arr[i];
            int targetIndex = value -1;
            int targetValue = arr[targetIndex];
            arr[i] = targetValue;
            arr[targetIndex] = value;
            cout << "do swaps between: " << value << " and " << targetValue << endl;
            swapsCount++;
            i--; //we decrement the i counter again so it would check the current index wether if it's still need to be swapped after the previous swap operations.
        }
    }

    cout << "endresults:" ;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return swapsCount;
}

int main() {
    vector<int> input = {2,3,4,1,5};
    minimumSwaps(input);
    return 1;
}