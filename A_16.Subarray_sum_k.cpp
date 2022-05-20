class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hm;
        int total=0,ans=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            if(total==k){
                ans++;
            }
            if(hm.find(total-k)!=hm.end()){
                ans+=hm[total-k];
            }
            hm[total]++;
        }
        return ans;
    }
};
