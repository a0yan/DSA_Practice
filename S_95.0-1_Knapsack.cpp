int helper(int index,int w, vector<int> &values, vector<int> &weights, int n, int mx_w,vector<vector<int>>&dp){
    if(w>=mx_w){
        return 0;
    }
    if(index==n){
        return 0;
    }
    if(dp[index][w]!=-1)
        return dp[index][w];
    int pick=0,not_pick=0;
    not_pick=helper(index+1,w,values,weights,n,mx_w,dp);
    if(w+weights[index]<=mx_w){
        pick=values[index]+helper(index+1,w+weights[index],values,weights,n,mx_w,dp);
    }
    return dp[index][w]=max(pick,not_pick);
    
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int mx_w)
{
	// Write your code here
    vector<vector<int>>dp(n+1,vector<int>(mx_w+1,-1));
    for(int index=n;index>=0;index--){
        for(int w=mx_w;w>=0;w--){
            if(index==n||w==mx_w){
                dp[index][w]=0;
                continue;
            }
     int pick=0,not_pick=0;
        not_pick=dp[index+1][w];
    if(w+weights[index]<=mx_w){ 
        pick=values[index]+dp[index+1][w+weights[index]];
    }
        dp[index][w]=max(pick,not_pick);
        }
    }
    return dp[0][0];
}
