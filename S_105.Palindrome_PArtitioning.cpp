#include<bits/stdc++.h>
bool check_palindrome(int start,int end,string& str){
    while(start<=end){
        if(str[start]!=str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int cut_helper(int start,int end,string& str,vector<vector<int>>&dp){
    if(start==end){
        return 0;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    if(check_palindrome(start,end,str)){
        return 0;
    }
    int num_cuts=INT_MAX;
    for(int c=start;c<end;c++){
        int partition_1=cut_helper(start,c,str,dp);
        int partition_2=cut_helper(c+1,end,str,dp);
        num_cuts=min(num_cuts,partition_1+partition_2+1);
    }
    return dp[start][end]=num_cuts;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n=str.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int start=n-1;start>=0;start--){
        for(int end=start;end<=n-1;end++){
            if(start==end){
                dp[start][end]=0;
            }
            else if(check_palindrome(start,end,str)){
                dp[start][end]= 0;
            }
            else{
                int num_cuts=INT_MAX;
                for(int c=start;c<end;c++){
                    int partition_1=dp[start][c];
                    int partition_2=dp[c+1][end];
                    num_cuts=min(num_cuts,partition_1+partition_2+1);
                }
                dp[start][end]=num_cuts;
            }
            
        }
    }
    return dp[0][n-1];
}
