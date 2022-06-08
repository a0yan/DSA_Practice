class Solution {
public:
    void helper(int index,int n,int k,vector<int>&temp,vector<vector<int>>& ans){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<=n;i++){
            temp.push_back(i);
            helper(i+1,n,k,temp,ans);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(1,n,k,temp,ans);
        return ans;
    }
};
