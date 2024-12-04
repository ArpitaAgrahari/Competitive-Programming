// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main(){
//     string s1,s2;
//     cin>>s1>>s2;
//     sort(s1.begin(),s1.end());
//     sort(s2.begin(),s2.end());
//     if(s1==s2){
//         cout<<"Anagram";
//     }
//     else{
//         cout<<"Not Anagram";
//     }
// }



//anagram using map

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    map<char,int> mp;
    for(int i=0;i<s1.size();i++){
        mp[s1[i]]++;
    }
    for(int i=0;i<s2.size();i++){
        mp[s2[i]]--;
    }
    for(auto x:mp){
        if(x.second!=0){
            cout<<"Not Anagram";
            return 0;
        }
    }
    cout<<"Anagram";
    return 0;
}
