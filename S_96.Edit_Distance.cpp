class Solution {
public:
    int helper(int n,int m,string s1,string s2,vector<vector<int>>&dp){
        if(n==0){
            return m; 
        }
        if(m==0){
            return n;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s1[n-1]==s2[m-1]){
            return dp[n][m]=helper(n-1,m-1,s1,s2,dp);
        }
        return dp[n][m]=1+min(helper(n-1,m,s1,s2,dp),min(helper(n,m-1,s1,s2,dp),helper(n-1,m-1,s1,s2,dp)));
        
    }
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0){
                    dp[i][j]=j;
                    continue;
                }
                if(j==0){
                    dp[i][j]=i;
                    continue;
                }
                if(s1[i-1]==s2[j-1]){
            dp[i][j]=dp[i-1][j-1];
        }
                else{
        dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};
