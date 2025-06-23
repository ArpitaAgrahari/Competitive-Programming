// 1. maximum subarray < k

#include <bits/stdc++.h>
using namespace std;
int maximumsubarray(int arr[], int n, int k)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum < k)
                maxSum = max(maxSum, sum);
        }
    }
    return (maxSum == INT_MIN) ? -1 : maxSum;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maximumsubarray(arr, n, k);
}

// optimized
#include <bits/stdc++.h>
using namespace std;

int maximumSubarrayLessThanK(int arr[], int n, int k)
{
    set<int> prefixSums;
    prefixSums.insert(0);
    int currSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        auto it = prefixSums.lower_bound(currSum - k + 1);
        if (it != prefixSums.end())
        {
            maxSum = max(maxSum, currSum - *it);
        }
        prefixSums.insert(currSum);
    }
    return (maxSum == INT_MIN) ? -1 : maxSum;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maximumSubarrayLessThanK(arr, n, k);
    return 0;
}

// 2. kadane algo
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxi = max(maxi, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << maxi << endl;
}