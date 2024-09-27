//k-jagged numbers: The number whose smallest prime factor is greater than or equal to the given k, it is called k-rough or k-jagged number.

//k-jagged numberz:
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vt(n+1,0);
    for(int i=2;i<=n;i++){
        if(vt[i]==0){
            for(int j=i;j<=n;j+=i){
                if(vt[j]==0) vt[j]=i;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(vt[i]>=5) cout<<i<<" ";
    }
    return 0;

}