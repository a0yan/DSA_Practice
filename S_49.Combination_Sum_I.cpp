class Solution {
public:
    void helper(vector<int>& candidates,int n, int target,vector<int>&temp,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(n==0){
            return;
        }
        if(candidates [n-1]<=target){
            temp.push_back(candidates[n-1]);
            helper(candidates,n,target-candidates[n-1],temp,ans);
            temp.pop_back();
            helper(candidates,n-1,target,temp,ans);
        }
        else{
            helper(candidates,n-1,target,temp,ans);            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=candidates.size();
        helper(candidates,n,target,temp,ans);
        return ans;
    }
};
