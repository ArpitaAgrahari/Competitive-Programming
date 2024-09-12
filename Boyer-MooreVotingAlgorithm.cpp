//Boyer more vt=oting algorihtm is used to find majoriy occurance of element in array 
//optimized algorithm o(1) coml
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findMajority(const vector<int>& arr){
    int key = -1;
    int count=0;
    for(int i=0;i<arr.size();++i){
        if(count==0){
            key=arr[i];
            count=1;
        }else if(arr[i]==key){
            count++;
        }else{
            count--;
        }
    }
    count=0;
    for(int i=0;i<arr.size();++i){
        if(arr[i]==key){
            count++;
        }
    }
    if(count> arr.size()/2){
        return key;
    }else{
        return -1;
    }
}
int main(){
    vector<int> arr1 = {3, 1, 3, 3, 2};
    cout << findMajority(arr1) << endl;
}