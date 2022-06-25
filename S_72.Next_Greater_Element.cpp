unordered_map<int,int> nextGreater(vector<int>& nums2){
        unordered_map<int,int>ans;
        stack<int>st;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and nums2[i]>=nums2[st.top()]){
                st.pop();
            }
            !st.empty()?ans[nums2[i]]=nums2[st.top()]:ans[nums2[i]]=-1;
            st.push(i);
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
class Solution {
public:
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>temp;
        temp=nextGreater(nums2);
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(temp[nums1[i]]);
        }
        return ans;
        
    }
};
