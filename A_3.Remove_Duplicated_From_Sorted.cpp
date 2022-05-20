class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int start_p=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                start_p++;
                nums[start_p]=nums[i];
            }
        }
        return start_p+1;
    }
};
