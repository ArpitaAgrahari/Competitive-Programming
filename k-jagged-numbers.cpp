//k-jagged numbers: The number whose smallest prime factor is greater than or equal to the given k, it is called k-rough or k-jagged number.

//k-jagged numberz:
#include<iostream>
#include<vector>
using namespace std;

bool isjagged(int n,int k){
    for(int i=2;i<=n;i++){
        if(n%i==0){
            if(i<k){
                return false;
            }else if(i>=k){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    if(isjagged(n,k)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}