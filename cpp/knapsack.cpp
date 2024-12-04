#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int n, int w, vector<int> &wt, vector<int> &val) {
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (wt[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}

int main() {
    int n, w;
    cout << "Enter weight: ";
    cin >> n >> w;

    if (n <= 0 || w <= 0) {
        cout << "Invalid input. Number of items and maximum weight must be positive." << endl;
        return 1;
    }

    vector<int> wt(n), val(n);
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
        if (wt[i] <= 0) {
            cout << "Invalid input. Weights must be positive." << endl;
            return 1;
        }
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        if (val[i] <= 0) {
            cout << "Invalid input. Values must be positive." << endl;
            return 1;
        }
    }

    int max_value = knapsack(n, w, wt, val);
    cout << "The maximum value that can be obtained is: " << max_value << endl;

    return 0;
}
