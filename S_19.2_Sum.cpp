class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0,end=n-1;
        vector<int>ans;
        unordered_map<int,int>hm;
        for(int i=0;i<n;i++){
            int val=nums[i];
            if(hm.find(target-val)!=hm.end()){
                ans.push_back(hm[target-val]);
                ans.push_back(i);
                return ans;
            }
            hm[val]=i;
        }
        return ans;
    }
};
