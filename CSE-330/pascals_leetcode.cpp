#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int limit=sqrt(n)+1;
    vector<int> prime;
    vector<int> low;
    vector<int> high;
    vector<int> mark(limit+1,0);
    for(int i=2;i<=limit;i++){
        if(mark[i]==0){
            prime.push_back(i);
            low.push_back(i*i);
            high.push_back(i*i);
        }
    }
    for(int i=0;i<prime.size();i++){
        for(int j=low[i];j<=n;j+=prime[i]){
            mark[j]=1;
        }
    }
    for(int i=2;i<=n;i++){
        if(mark[i]==0){
            cout<<i<<" ";
        }
    }
    return 0;
}