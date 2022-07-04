class Solution {
public:
    int helper(int index,int amount,vector<int>&nums,int n,vector<vector<int>>&dp){
        if(amount==0){
            return 1;
        }
        if(index==n){
            return 0;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int pick=0;
        int not_pick=0;
        if(nums[index]<=amount){
            pick=helper(index+1,amount-nums[index],nums,n,dp);
        }
        not_pick=helper(index+1,amount,nums,n,dp);
        return dp[index][amount]=pick||not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        for(int &num:nums)
            total+=num;
        if(total%2!=0)
            return false;
        total/=2;
        vector<vector<int>>dp(n+1,vector<int>(total+1,-1));
        return helper(0,total,nums,n,dp);
        
    }
};
