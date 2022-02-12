#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


void minimumBribes(vector<int> q) {
    int totalBriberiesNeeded = 0;
    for(int i = 0; i < q.size(); i++) {
       if(q[i] - (i + 1) > 2) {
           //means it's not actually possible
           cout << "Too chaotic" <<endl;
           return;
       }
       for(int j = max(0, q[i] - 2); j < i ; j++ ) {
           if (q[j] > q[i]) {
               totalBriberiesNeeded++;
            }
       }
    }
    cout << totalBriberiesNeeded << endl;
}



int main() {

    vector<int> input = {1,2,5,3,7,8,6,4};

    minimumBribes(input);
    return 1;
}