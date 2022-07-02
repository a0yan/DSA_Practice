	int helper(int idx,int pre_idx,int arr[],int n,vector<vector<int>>&dp){
	    if(idx==n){
	        return 0;
	    }
	    if(dp[idx][pre_idx+1]!=-1){
	        return dp[idx][pre_idx+1];
	    }
	    int pick=0;
	    int not_pick=helper(idx+1,pre_idx,arr,n,dp);
	    if(pre_idx==-1||arr[idx]>arr[pre_idx]){
	        pick= arr[idx]+helper(idx+1,idx,arr,n,dp);
	    }
	    return dp[idx][pre_idx+1]=max(pick,not_pick);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	   // return helper(0,-1,arr,n,dp);
	    for(int idx=n;idx>=0;idx--){
	        for(int pre_idx=idx-1;pre_idx>=-1;pre_idx--){
	            if(idx==n){
	                dp[idx][pre_idx+1]=0;
	            }
	            else{
	     int pick=0;
	      int not_pick=dp[idx+1][pre_idx+1];
	    if(pre_idx==-1||arr[idx]>arr[pre_idx]){
	        pick= arr[idx]+dp[idx+1][idx+1];
	    }
	    dp[idx][pre_idx+1]=max(pick,not_pick);
	   }
	            
	  }
	    }
	    return dp[0][0];
	}  
};
