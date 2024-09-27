// next permutation :  

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int next_permutation(vector<int> &v){
    int n=v.size();
    int i=n-2;
    while(i>=0 && v[i]>=v[i+1]){
        i--;
    }
    if(i<0){
        return 0;
    }
    int j=n-1;
    while(v[j]<=v[i]){
        j--;
    }
    swap(v[i],v[j]);
    reverse(v.begin()+i+1,v.end());
    return 1;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    next_permutation(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>