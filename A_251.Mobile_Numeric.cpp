int keypad[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,0,10}};
	int dx[5]={0,0,-1,0,1};
	int dy[5]={0,-1,0,1,0};
	
	long long rec(int i , int j ,int n , vector<vector<long long>> &dp)
	{
	    if(i<0 || j<0 || i>=4 || j>=3 || keypad[i][j]==10) return 0;
	    if(n<=1) return n;
	    
	    if(dp[keypad[i][j]][n]!=-1) return dp[keypad[i][j]][n];
	    
	    long long ans=0;
	    for(int d=0 ;d<5 ;++d)
	    {
	        ans+=rec( i+dx[d] , j+dy[d] , n-1 , dp );
	    }
	    return dp[keypad[i][j]][n]=ans;
	}
	
	long long getCount(int N)
	{
		vector<vector<long long>> dp(10 , vector<long long> (26 , -1));
		
		long long ans=0;
		for(int i=0 ; i<4 ;++i)
		{
		    for(int j=0 ; j<3 ;++j) ans+=rec(i,j,N,dp);
		}
		return ans;
	}
