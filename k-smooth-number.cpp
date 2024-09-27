//k-smooth numbers or k-friable numbers: 

#include<iostream>
using namespace std;
bool isSmooth(int n,int k){
    for(int i=n;i<=2;i--){
        if(n%i==0){
            if(i>k){
                return false;
            }else if(i<=k){
                return true;
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