//k-smooth numbers or k-friable numbers: 

#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
bool isSmooth(int n,int k){
    for(int i=n;i>=2;i--){
        if(n%i==0){
            if(isPrime(i)){
                if(i<=k){
                    return true;
                }else{
                    return false;
                }
            }
        }
    }
    return false;
}

int main(){
    int n,k;
    cin>>n>>k;
    if(isSmooth(n,k)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}