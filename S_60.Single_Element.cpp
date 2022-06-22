class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int end=nums.size()-1;
        int start=0;
        if(start==end){
            return nums[start];
        }
        while(start<end){
            int mid=start+(end-start)/2;
            if((mid==start && nums[mid]!=nums[mid+1])||(mid==end and nums[mid]!=nums[mid-1])){
                return nums[mid];
            }
            else if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(mid==start || nums[mid]!=nums[mid-1]){
                if((mid-start)%2==0){
                    start=mid+2;
                }
                else{
                    end=mid-1;
                }
            }
            else if (mid==end||nums[mid]!=nums[mid+1]){
                if((end-mid)%2==0){
                    end=mid-2;
                }
                else{
                    start=mid+1;
                }
            }
            
        }
        return nums[start];
    }
};
