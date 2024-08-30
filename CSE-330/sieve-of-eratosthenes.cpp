//seive of eratosthenes
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool prime[n+1];
    for(int i=0;i<=n;i++){
        prime[i]=true;
    }
    for(int p=2;p*p<=n;p++){
        if(prime[p]==true){
            for(int i=p*p;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}