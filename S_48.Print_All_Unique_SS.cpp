class Solution
{
public:

void solve(int i,int n,vector<int>&nums,vector<int>&subset,vector<vector<int>>&ans)
{
    if(i==n)
    {
        ans.push_back(subset);
        return;
    }
    //take
    subset.push_back(nums[i]);
    solve(i+1,n,nums,subset,ans);
    //not_take 
    subset.pop_back();
    while(i+1<nums.size() and nums[i]==nums[i+1])i++;
    solve(i+1,n,nums,subset,ans);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    vector<vector<int>>ans;
    vector<int>subset;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    solve(0,n,nums,subset,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
};
