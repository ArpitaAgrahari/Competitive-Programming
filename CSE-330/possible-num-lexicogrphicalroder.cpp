//Problem Statement:  You are given a number n,print all possible numbers from 1-n in lexicographical order using prefix and recursove call.

#include <iostream>
using namespace std;
void check(int curr,int n) {
    if(curr>n) return;
    cout<<curr<< " ";
    for(int i=0;i<=9;++i) {
        int next=curr*10+i;
        if(next>n) return;
        check(next,n);
        
    }
}
void printorder(int n) {
    for (int i=1;i<=9;++i) {
        check(i,n);
    }
}
int main(){
    int n;
    cin>>n;
    printorder(n);
    return 0;
}