class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num_1=-1,num_2=-1,c_1=0,c_2=0;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]==num_1){
                c_1++;
            }
            else if (nums[i]==num_2){
                c_2++;
            }
            else if(c_1==0){
                num_1=nums[i];
                c_1=1;
            }
            else if (c_2==0){
                num_2=nums[i];
                c_2=1;
            }
            else{
                c_1--;
                c_2--;
            }
        }
        int count_1=0,count_2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==num_1){
                count_1++;
            }
            else if (nums[i]==num_2){
                count_2++;
            }
        }
        if(count_1>n/3){
            ans.push_back(num_1);
        }
        if(count_2>n/3){
            ans.push_back(num_2);
        }
        return ans;
    }
};
