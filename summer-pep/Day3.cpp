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
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maximumsubarray(arr, n);
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