class Solution
{
    public:
    //Function to find the maximum number of cuts.
        int helper(int n,int x ,int y,int z,vector<int>&dp){
        if (n<0)
            return -INT_MAX;
        if (n==0)
            return 0;
        if (dp[n]!=-1)
            return dp[n];
        dp[n]=max(helper(n-x,x,y,z,dp),max(helper(n-y,x,y,z,dp),helper(n-z,x,y,z,dp)));
        if (dp[n]==-INT_MAX)
            return -INT_MAX;
        dp[n]+=1;
        return dp[n];
        }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
       vector<int>dp(n+1,-1);
       int val=helper(n,x,y,z,dp);
       if(val==-INT_MAX){
           return 0;
       }
       return val;
        
        //Your code here
    }
