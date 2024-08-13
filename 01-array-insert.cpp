//insertion
//1,2,3,4,5,--23--,6,7,8,9

#include<iostream>
using namespace std;
void insert(int arr[],int *n,int pos,int key){
    (*n)++;
    for(int i=(*n-1);i>=pos;i--){
        arr[i] = arr[i-1];
    }
    arr[pos-1] = key;
}
int main(){
    int arr[100] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;

    insert(arr, &n,5,23);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}