class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
       vector<int>dp(mx+1,0);
        for(int num:nums){
            dp[num]++;
        }
        int include=dp[0];
        int exclude=0;
        int ans=0;
        for(int i=1;i<dp.size();i++){
            int inc=exclude+dp[i]*i;
            int exc=max(include,exclude);
            ans=max(inc,exc);
            include=inc;
            exclude=exc;
        }
        return ans;
    }
};
