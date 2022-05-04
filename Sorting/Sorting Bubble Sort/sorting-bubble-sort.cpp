#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void countSwaps(vector<int> a) {
    int numSwaps = 0;
    int lastElement = 0;
    int firstElement = 0;

    for(int i = 0; i < a.size(); i++) {
        for(int j = i + 1; j < a.size(); j++) {
            if(a[i] > a[j]) {
                numSwaps++;
                // cout << "swaps " << a[i] << " with " << a[j] << endl;
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    firstElement = a[0];
    lastElement = a[a.size() - 1];


    cout << "Array is sorted in " << numSwaps << " swaps." << endl;
    cout << "First Element: " << firstElement << endl;
    cout << "Last Element: " << lastElement << endl;
    

//    cout << "arrays:";
//    for(int i = 0; i < a.size(); i++) {
//        cout << a[i] << " ";
//    }
}

int main() {

    vector<int> input = {4,2,3,1};
    countSwaps(input);
    return 0;
}