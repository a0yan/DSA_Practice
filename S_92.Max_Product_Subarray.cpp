class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_p=1;
        int min_p=1;
        int ans=INT_MIN;
        int n=nums.size();
        if(n==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            int temp=max_p;
            max_p=max(max_p*nums[i],max(min_p*nums[i],nums[i]));
            min_p=min(min_p*nums[i],min(temp*nums[i],nums[i]));
            ans=max(ans,max(min_p,max_p));
            // ans=max(ans,max(max_p*nums[i],min_p*nums[i]));
            
        }
        return ans;
    }
};
