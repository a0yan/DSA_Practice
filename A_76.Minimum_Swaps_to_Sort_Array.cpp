class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    vector<vector<int>>mod;
	    for(int i=0;i<n;i++){
	        mod.push_back({nums[i],i});
	    }
	    int ans=0;
	    sort(mod.begin(),mod.end());
	    vector<bool>vis(n,false);
	    for(int i=0;i<n;i++){
	        if(vis[i]||mod[i][1]==i){
	            continue;
	        }
	        int j=mod[i][1];
	        int cycles=0;
	        while(vis[j]==false){
	            vis[j]=true;
	            j=mod[j][1];
	            cycles++;
	        }
	        if(cycles>0){
	            ans+=cycles-1;
	        }
	    }
	    return ans;
	}
