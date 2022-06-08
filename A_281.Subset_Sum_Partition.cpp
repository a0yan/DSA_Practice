class Solution{
public:
    int helper(int& N, int total,int arr[],vector<vector<int>>& dp){
        if(total==0){
            return 1;
        }
        if(N==0){
            return 0;
        }
        if(dp[N][total]!=-1)
        return dp[N][total];
        if(arr[N-1]<=total){
        dp[N][total]=helper(N-1,total-arr[N-1],arr,dp)||helper(N-1,total,arr,dp);
        }
        else{
            dp[N][total]=helper(N-1,total,arr,dp);
        }
        return dp[N][total];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int total=0;
        for(int i=0;i<N;i++)
        total+=arr[i];
        if(total%2)
        return 0;
        total/=2;
        vector<vector<int>>dp(N+1,vector<int>(total+1,-1));
        return helper(N-1,total,arr,dp);
        
    }
};
