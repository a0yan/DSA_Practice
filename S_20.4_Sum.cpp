class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int k,l;
        for(int i=0;i<(int)nums.size();i++){
            for(int j=i+1;j<(int)nums.size();j++){
                k=j+1;  l=(int)nums.size()-1;
                while(k<l){
                    if((long)nums[i]+nums[j]+nums[k]+nums[l]==target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        result.push_back(temp);
                        while(k+1<l && nums[k]==nums[k+1]) //Eliminate Duplicate k
                          k++;                  
                        while(l-1>k && nums[l]==nums[l-1])  //Eliminate Duplicate j
                            l--;
                        k++;
                        l--;
                    
                    }else if((long)nums[i]+nums[j]+nums[k]+nums[l]<target){  
                        k++;                          //Array is sorted, so to increment sum choose bigger k
                    }else{
                        l--;                           //Array is sorted, so to increment sum choose smaller l
                    }
                   
                }
                while(j+1<(int)nums.size() && nums[j]==nums[j+1])  //Eliminate Duplicate j
                    j++;
            }
            while(i+1<(int)nums.size() && nums[i]==nums[i+1])  //Eliminate Duplicate i
                    i++;
        }
        return result;
    }
};
