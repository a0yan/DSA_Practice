class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int c=0 ,bc=0;
        // int j=0;
        int n=nums.size();
        while(c<k){
            bc+=nums[n-1-c];
            c++;
        }
        int ans=bc;
        int total=0;
        for(int i=0;i<k;i++){
            bc-=nums[n-k+i];
            total+=nums[i];
            // cout<<total
            ans=max(ans,total+bc);
        }
        return ans;
    }
};
