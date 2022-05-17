class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[0];
        int curr_sum=nums[0];
        for(int i=1;i<n;i++){
            curr_sum=max(curr_sum+nums[i],nums[i]);
            mx=max(mx,curr_sum);
        }
        return mx;
        
    }
};
