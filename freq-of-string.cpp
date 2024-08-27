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
#include <iostream>
using namespace std;
int main() {
    string s1;
    cin>>s1;
    int count=0;
    int arr[26]={0};
    for(int i=0;i<s1.length();i++){
        arr[s1[i]-'a']=1;
    }
    for(int i=0;i<26;i++){
        if(arr[i]==0){
            count++;
        }
    }
    cout<<count;
    return 0;
} 