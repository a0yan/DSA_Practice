int helper(int i,int j,vector<int> &arr,vector<vector<int>>&dp){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int steps=arr[i-1]*arr[k]*arr[j]+helper(k+1,j,arr,dp)+helper(i,k,arr,dp);
        ans=min(ans,steps);
        
    }
    return dp[i][j]=ans;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N,vector<int>(N,0));
    for(int i=N-1;i>=1;i--){
        for(int j=i+1;j<N;j++){
            if(i==j){
                dp[i][j]=0;
            }
            else{
                int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int steps=arr[i-1]*arr[k]*arr[j]+dp[k+1][j]+dp[i][k];
        ans=min(ans,steps);
        
    }
    dp[i][j]=ans;
            }
        }
    }
    return dp[1][N-1];
    // Write your code here.
}
