class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        int can_reject=n-k;
        vector<int>st;
        // st.push_back(nums[0]);
        for(int i=0;i<n;i++){
            while(!st.empty() and can_reject and st.back()>nums[i]){
                st.pop_back();
                can_reject--;
            }
            st.push_back(nums[i]);
        }
        while(!st.empty()and can_reject){
            st.pop_back();
            can_reject--;
        }
        return st;
    }
};
