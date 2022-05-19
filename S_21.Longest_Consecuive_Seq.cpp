class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map <int,int> hm;
        int m_c=0;
        for(int& val:nums){
            hm[val]++;
        }
        for(int i=0;i<nums.size();i++){
            if(hm[nums[i]-1]==0){
                int c=0;
                int val=nums[i];
                while(hm[val]!=0){
                    val++;
                    c++;
                    // hm.erase(val);
                }
                m_c=max(m_c,c);
            }
        }
        return m_c;
        
    }
};
