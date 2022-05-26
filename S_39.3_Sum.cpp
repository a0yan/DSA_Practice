class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            int start=i+1;
            int end=n-1;
            while(start<end){
                int total=nums[start]+nums[end]+nums[i];
                if(total>0){
                    end--;
                }
                else if (total<0){
                    start++;
                }
                else{
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                    ans.push_back(temp);
                    while(start<end and nums[start]==nums[start+1]){
                        start++;
                    }
                    while(start<end and nums[end]==nums[end-1]){
                        end--;
                    }
                    start++;
                    end--;
                }
            }
            while(i<n-1 and nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};
