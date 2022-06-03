class Solution {
public:
    void helper(vector<int>& candidates,int n ,int target,vector<int>temp,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(n==0){
            return;
        }
        if(candidates[n-1]<=target){
            temp.push_back(candidates[n-1]);
            helper(candidates,n-1,target-candidates[n-1],temp,ans);
            temp.pop_back();
            while(n!=1 and candidates[n-1]==candidates[n-2]){
                n--;
            }
            helper(candidates,n-1,target,temp,ans);
        }
        else{
         helper(candidates,n-1,target,temp,ans);   
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        helper(candidates,n,target,temp,ans);
    return ans;
    }
};
