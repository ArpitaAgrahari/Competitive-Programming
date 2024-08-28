#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {2,1,3,5,6};
    int k = 5;
    int mul = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<k-1;i++){
            int* minElementPtr = min_element(arr, arr + n);
             *minElementPtr *= mul;
        }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}