class Solution {
public:
    vector<vector<int>>dp;
    int helper(int start,int end,vector<int>&nums){
        if(start>end){
            return 0;
        }
        if(dp[start][end]!=-1)
            return dp[start][end];
        int ans=0;
        for(int k=start;k<=end;k++){
            int coins=nums[start-1]*nums[k]*nums[end+1]+helper(start,k-1,nums)+helper(k+1,end,nums);
            ans=max(coins,ans);
        }
        return dp[start][end]=ans;
    }
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        dp.assign(n,vector<int>(n,0));
        for(int start=n-2;start>=1;start--){
            for(int end=start;end<=n-2;end++){
        int ans=0;
        for(int k=start;k<=end;k++){
            int coins=nums[start-1]*nums[k]*nums[end+1]+dp[start][k-1]+dp[k+1][end];
            ans=max(coins,ans);
        }
        dp[start][end]=ans;
            }
        }
        return dp[1][n-2];
        
    }
};
