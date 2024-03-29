class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int l = 0, r = nums.size() - 1;
        int n=nums.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            if((mid<=l||nums[mid]>nums[mid-1])&&(mid>=r||nums[mid]>nums[mid+1])){
                return mid;
            }
            if (mid==r||nums[mid] > nums[mid + 1])
                r = mid-1;
            else
                l = mid + 1;
        }
        return -1;
    } 
};
