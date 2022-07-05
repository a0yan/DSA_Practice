#include<bits/stdc++.h>
int helper(int k, int n,vector<vector<int>>&dp){
    if(n<=1||k<=1){
        return n;
    }
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;i++){
        int cut=helper(k,n-i,dp);
        int not_cut=helper(k-1,i-1,dp);
        ans=min(ans,max(cut,not_cut));
    }
    return dp[n][k]=ans+1;
}
int cutLogs(int k, int n)
{
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return helper(k,n,dp);
    // Write your code here.
    
}
// Axes--k
// capacity--n
