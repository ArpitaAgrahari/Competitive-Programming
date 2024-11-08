//YOu have a binary stringS of length N. int the one operarion you can select a substring of S and reverse it.find the minimum number of operations required to sort this binary string.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin>>str;
    int n=str.size();
    int ans=0;
    for(int i=0;i<n;i++) {
        if (str[i]=='0') {
            ans++;
            while(i<n&&str[i]=='0') {
                i++;
            }
        }
    }
    if(str[n-1]=='1'){
        ans++;
    }
    cout<<ans<< endl;
    return 0;
}