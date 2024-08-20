#include<iostream>
using namespace std;
int main(){
    int arr[3][3] = {{1,2,3},{4,5,6}};
    int m =3;
    int n=3;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
    }
}