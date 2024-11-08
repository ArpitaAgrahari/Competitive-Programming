#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>

using namespace std;

int calculateMinCost(const string& A, const unordered_set<string>& substrings, int C, int D) {
    int n = A.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; i + j <= n; ++j) {
            string subStr = A.substr(i, j);
            if (substrings.count(subStr)) {
                dp[i + j] = min(dp[i + j], dp[i] + C);
            } else {
                // Create a mutable copy of the substring
                string reversedSubStr = subStr;
                reverse(reversedSubStr.begin(), reversedSubStr.end());
                if (substrings.count(reversedSubStr)) {
                    dp[i + j] = min(dp[i + j], dp[i] + D);
                }
            }
        }
    }

    return dp[n] == INT_MAX ? -1 : dp[n];
}

int main() {
    string A, B;
    int C, D;
    cin >> A >> B >> C >> D;

    unordered_set<string> substrings;
    int m = B.size();
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            substrings.insert(B.substr(i, j - i));
        }
    }

    int res = calculateMinCost(A, substrings, C, D);
    if (res == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}