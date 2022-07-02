// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         if(n==0){
//             return 0;
//         }
//         vector<int>dp(n,1);
//         for(int i=1;i<n;i++){
//             for(int j=0;j<i;j++){
//                 if(nums[j]<nums[i])
//                 dp[i]=max(dp[i],dp[j]+1);
//             }
//         }
//         return *max_element(dp.begin(),dp.end());
//     }
// };
// class Solution {
// public:
//     int helper(vector<int>& nums,int index,int pre_index,int n,vector<vector<int>>&dp){
//         if(index==n){
//             return 0;
//         }
//         if(dp[pre_index+1][index]!=-1){
//             return dp[pre_index+1][index];
//         }
//         int pick=0;
//         int not_pick=0;
//         if(pre_index==-1||nums[index]>nums[pre_index]){
//             pick=1+helper(nums,index+1,index,n,dp);
//         }
//         not_pick=helper(nums,index+1,pre_index,n,dp);
//         return dp[pre_index+1][index]=max(pick,not_pick);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         return helper(nums,0,-1,nums.size(),dp);
        
//     }
// };
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//         for(int index=n-1;index>=0;index--){
//             for(int pre_index=index-1;pre_index>=-1;pre_index--){
//                 int pick=0;
//                 int not_pick=0;
//             if(pre_index==-1||nums[index]>nums[pre_index]){
//                 pick=1+dp[index+1][index+1];
//             }
//             not_pick=dp[index+1][pre_index+1];
//             dp[index][pre_index+1]=max(pick,not_pick);
//             }
//         }
//         return dp[0][0];

//     }
// };
