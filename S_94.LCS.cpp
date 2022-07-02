class Solution {
public:
    int helper(string s1,string s2,int idx1,int idx2,int n,int m,vector<vector<int>>&dp){
        if(idx1==n||idx2==m){
            return 0;
        }
        int ans=0;
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        if(s1[idx1]==s2[idx2]){
            ans=1+helper(s1,s2,idx1+1,idx2+1,n,m,dp);
        }
        else{
            ans=max(helper(s1,s2,idx1+1,idx2,n,m,dp),helper(s1,s2,idx1,idx2+1,n,m,dp));
        }
        return dp[idx1][idx2]=ans;
        
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int idx1=n-1;idx1>=0;idx1--){
            for(int idx2=m-1;idx2>=0;idx2--){
                int ans=0;
            if(s1[idx1]==s2[idx2]){
            ans=1+dp[idx1+1][idx2+1];
        }
        else{
            ans=max(dp[idx1+1][idx2],dp[idx1][idx2+1]);
        }
        dp[idx1][idx2]=ans;
        }
        }
        return dp[0][0];
    }
};
