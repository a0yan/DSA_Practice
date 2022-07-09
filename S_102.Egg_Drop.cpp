class Solution {
public:
    vector<vector<int>>dp;
    int helper(int k,int n){
       if(n==0||n==1) return n;  //if no. of floor 0 , 1 return n:
        if(k==1) return n;
        if(dp[k][n]!=-1)
            return dp[k][n];
        int ans=INT_MAX;
        for(int f=1;f<=n;f++){
            int egg_break=helper(k-1,f-1);
            int not_break=helper(k,n-f);
            ans=min(ans,max(egg_break,not_break));
        }
        return dp[k][n]=ans+1;
    }
    int superEggDrop(int k, int n) {
        dp.assign(k+1,vector<int>(n+1,-1));
        return helper(k,n);
    }
};
