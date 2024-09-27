//k-jagged numbers: The number whose smallest prime factor is greater than or equal to the given k, it is called k-rough or k-jagged number.

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> spf(n+1,0);
    for(int i=2;i<=n;i++) {
        if(spf[i]==0) {
            for(int j=i;j<=n;j+=i) {
                if(spf[j]==0) spf[j]=i;
            }
        }
    }
    for(int i=2;i<=n;i++) {
        if(spf[i]>=5) cout<<i<<" ";
    }
    return 0;
}