class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones ,max_ones=0;
        int i=0;
        int n=nums.size();
        while(i<n){
            ones=0;
            while(i<n and nums[i]==1){
                ones++;
                max_ones=max(max_ones,ones);
                i++;
            }
            i++;
        }
        return max_ones;
    }
};
