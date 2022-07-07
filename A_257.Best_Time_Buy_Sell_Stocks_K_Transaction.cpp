class Solution {
public:
    vector<vector<vector<int>>>dp;
    int helper(int index,int k,int buy,vector<int>&prices){
        int n=prices.size();
        if(index==n||k==0){
            return 0;
        }
        if(dp[index][k][buy]!=-1){
            return dp[index][k][buy];
        }
        int max_profit=0;
        if(buy){
            int take=-prices[index]+helper(index+1,k,0,prices);
            int not_take=helper(index+1,k,1,prices);
            max_profit=max(take,not_take);
        }
        else{
            int sold=prices[index]+helper(index+1,k-1,1,prices);
            int not_sold=helper(index+1,k,0,prices);
            max_profit=max(sold,not_sold);
        }
        return dp[index][k][buy]=max_profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        dp.assign(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return helper(0,k,1,prices);
    }
};
