//deletion
#include<iostream>
using namespace std;
void deletion(int array[],int *n,int pos){
    if(pos < 0 || pos>*n){
        return;
    }
    for(int i = pos;i<=(*n-1);i++){
        array[i-1] = array[i];
    }
    (*n)--;
}
int main(){ 
    int array[100] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    deletion(array ,&n, 4);
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}