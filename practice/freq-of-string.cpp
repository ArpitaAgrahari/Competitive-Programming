//given two string and s 1 and s2 you have to find the frequency of s2 in s1.
// #include <iostream>
// using namespace std;

// int main() {
//     string s1,s2;
//     cin>>s1>>s2;
//     int count=0;
//     for(int i=0;i<s1.length();i++){
//         if(s1[i]==s2[0]){
//         int j=0;
//         while(j<s2.length() && s1[i+j]==s2[j]){
//             j++;
//         }
//         if(j==s2.length()){
//             count++;
//             }
//         }
//     }
//     cout<<count;
//     return 0;
// }

//to check how many alphabet is not present in the string s1
// #include <iostream>
// using namespace std;
// int main() {
//     string s1;
//     cin>>s1;
//     int count=0;
//     int arr[26]={0};
//     for(int i=0;i<s1.length();i++){
//         arr[s1[i]-'a']=1;
//     }
//     for(int i=0;i<26;i++){
//         if(arr[i]==0){
//             count++;
//         }
//     }
//     cout<<count;
//     return 0;
// } 


//anagram of a string
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

// //anagram of a string without using sort using map
// #include<iostream>
// using namespace std;
// int main(){
//     string s1,s2;
//     cin>>s1>>s2;
//     int mp[26]={0};
//     for(int i=0;i<s1.length();i++){
//         mp[s1[i]-'a']++;
//     }
//     for(int i=0;i<s2.length();i++){
//         mp[s2[i]-'a']--;
//     }
//     for(int i=0;i<26;i++){
//         if(mp[i]!=0){
//             cout<<"Not Anagram";
//             return 0;
//         }
//     }
//     cout<<"Anagram";
//     return 0;
// }




//anaagram of a string without using sort
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     string s1,s2;
//     cin>>s1>>s2;
//     map<char,int> mp;
//     for(int i=0;i<s1.size();i++){
//         mp[s1[i]]++;
//     }
//     for(int i=0;i<s2.size();i++){
//         mp[s2[i]]--;
//     }
//     for(auto x:mp){
//         if(x.second!=0){
//             cout<<"Not Anagram";
//             return 0;
//         }
//     }
//     cout<<"Anagram";
//     return 0;
// }
