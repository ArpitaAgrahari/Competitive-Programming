//71 leetcode
//simplifying the path
//stack and replcaing multiple slashes with single slash
//i have to erase the last slash given at the ned of the string
//i have to replace 2 dots then push and 3 dots then pop and push a single slash

#include <bits/stdc++.h>
using namespace std;
int main(){
    string path;
    cin>>path;
    stack<string> s;
    string temp="";
    for(int i=0;i<path.size();i++){
        if(path[i]=='/'){
            if(temp.size()>0){
                s.push(temp);
                temp="";
            }
        }
        else{
            temp+=path[i];
        }
    }
    if(temp.size()>0){
        s.push(temp);
    }
    stack<string> s1;
    while(!s.empty()){
        string temp=s.top();
        s.pop();
        if(temp==".."){
            if(!s1.empty()){
                s1.pop();
            }
        }
        else if(temp=="."){
            continue;
        }
        else{
            s1.push(temp);
        }
    }
    stack<string> s2;
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    string ans="";
    while(!s2.empty()){
        ans+="/";
        ans+=s2.top();
        s2.pop();
    }
    if(ans.size()==0){
        ans+="/";
    }
    cout<<ans<<endl;
    return 0;
}
