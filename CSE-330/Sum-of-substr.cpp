//Problem statement : given a array print all the sum of the subset genrated from it, in the increasing order.

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void Sums(const vector<int>& arr, int index, int curr, vector<int>& sub) {
    if (index == arr.size()) {
        sub.push_back(curr);
        return;
    }
    Sums(arr, index + 1, curr + arr[index], sub);
    Sums(arr, index + 1, curr, sub);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> sub;
    Sums(arr, 0, 0, sub);
    sort(sub.begin(), sub.end());
    for (int sum : sub) {
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}


