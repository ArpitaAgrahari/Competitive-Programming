//seive of eratosthenes

//seive of eratothenes is an algorithm to find all prime numbers upto a given number n
//most efficient way to find all prime numbers upto n
//it works by iteratively marking the multiples of primes as composite, starting from 2
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
    }return 0;   
}