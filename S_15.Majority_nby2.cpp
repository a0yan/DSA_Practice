class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int maj=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==maj){
                count++;
            }
            else if(nums[i]!=maj){
                count--;
            }
            if(count<0){
                maj=nums[i];
                count=1;
            }
        }
        
        return maj;
    }
};
