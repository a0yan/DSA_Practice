class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cz=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[i-cz]=nums[i];
            }
            else{
                cz++;
            }
        }
        int j=n-1;
        while(cz!=0){
            nums[j]=0;
            cz--;
            j--;
        }
    }
};
