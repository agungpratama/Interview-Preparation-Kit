#include <stdio.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int maximumToys(vector<int> prices, int k) {
    int result = 0;
    int moneyLeft = k;
    sort(prices.begin(), prices.end());

    for (int i = 0; i < prices.size(); i++) {
        if(prices[i] <= moneyLeft) {
            cout << prices[i] << " is less than " << moneyLeft << endl;
            moneyLeft -= prices[i];
            result++;
        }
    }
    cout << "result:" << result << endl;

    return result;
}
int main() {

    vector<int> input = {1,2,3,4};
    maximumToys(input,7);
    return 0;
}