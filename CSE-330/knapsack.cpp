//knapsack probelm 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int knapsack(int n,int w,vector<int> &wt,vector<int> &val){
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main(){
    int n,w;
    cin>>n>>w;
    vector<int> wt(n),val(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    cout<<knapsack(n,w,wt,val);
    return 0;
}
//time complexity : O(n*w)
//space complexity : O(n*w)