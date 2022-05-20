class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> hm;
        int n=nums.size();
        int total=0,count=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
            while(total<0){
                total+=k;
            }
            if(total%k==0){
                count++;
            }
            if(hm.find(total%k)!=hm.end()){
                count+=hm[total%k];
            }
            hm[total%k]++;
        }
        return count;
    }
};
