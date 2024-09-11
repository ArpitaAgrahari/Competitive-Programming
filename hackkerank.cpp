// You are given an array of integers arr of size N. Your task is to partition the array into two non-empty subarrays such that the sum of elements in the left subarray is strictly greater than the sum of elements in the right subarray. Return the minimum index where this partition can occur. Input: • The first line contains an integer N, the number of elements in the array arr. • The second line contains N space-separated integers representing the array arr. Output: • Print the minimum index i such that the sum of elements from arr[0] to arr[i] (left subarray) is strictly greater than the sum of elements from arr[i+1] to arr[N-1] (right subarray). • If no such partition exists, print -1.

// Input Format

// 5

// 3 1 4 1 2

// Constraints

// 2≤N≤105 −106≤arr[i]≤106

// Output Format

// 2

#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int leftsum=0;
    for(int i=0;i<n;i++){
        sum-=arr[i];
        if(leftsum>sum){
            cout<<i<<endl;
            return 0;
        }
        leftsum+=arr[i];
    }
    cout<<-1<<endl;
    return 0;
}
