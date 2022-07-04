class Solution {
public:
    int helper(int index, vector<int>&coins,int amount,int n,vector<vector<int>>&dp){
        if(amount==0){
            return 0;
        }
        if(index==n){
            return INT_MAX;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        long long int pick=INT_MAX;
        long long  int not_pick=INT_MAX;
        long long int ans=0;
        if(coins[index]<=amount){
            pick=helper(index,coins,amount-coins[index],n,dp);
            if(pick<INT_MAX){
                pick++;
            }
            
        }
        not_pick=helper(index+1,coins,amount,n,dp);
        ans=min(pick,not_pick);
        if(ans>=INT_MAX){
            ans=INT_MAX;
        }
        return dp[index][amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        for(int index=n;index>=0;index--){
            for(int total=0;total<=amount;total++){
                if(total==0){
                    dp[index][total]=0;
                }
                else if(index==n){
                    dp[index][total]=INT_MAX;
                }
                else{
                    long long int pick=INT_MAX;
                    long long  int not_pick=INT_MAX;
                    long long int ans=0;
                    if(coins[index]<=total){
                        pick=dp[index][total-coins[index]];
                        if(pick<INT_MAX){
                            pick++;
                        }

                    }
                    not_pick=dp[index+1][total];
                    ans=min(pick,not_pick);
                    if(ans>=INT_MAX){
                        ans=INT_MAX;
                    }
                    dp[index][total]=ans;
                }
            }
        }
        return dp[0][amount]!=INT_MAX?dp[0][amount]:-1;
    }
};
