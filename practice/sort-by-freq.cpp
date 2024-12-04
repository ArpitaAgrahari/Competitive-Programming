
//sort decreasing order based on frequency
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "tree";
    unordered_map<char, int> mp;
    for(int i = 0; i < s1.size(); i++){
        mp[s1[i]]++;
    }
    vector<pair<int, char>> freq;
    for(auto it : mp){
        freq.push_back({it.second, it.first});
    }
    sort(freq.begin(), freq.end(), greater<pair<int, char>>());
    string result = "";
    for(auto it : freq){
        result += string(it.first, it.second);
    }
    cout << result << endl;

    return 0;
}
