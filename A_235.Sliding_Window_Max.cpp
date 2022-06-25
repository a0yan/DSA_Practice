typedef pair<int,int>ii;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<ii>dq;
        int i=0;
        while(i<k){
            while(!dq.empty() and dq.back().first<nums[i]){
                dq.pop_back();
            }
            dq.push_back({nums[i],i});
            i++;
        }
        int n=nums.size();
        vector<int>ans;
        for(int i=k;i<n;i++){
            ans.push_back(dq.front().first);
            while(!dq.empty() and dq.front().second<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() and dq.back().first<nums[i]){
                dq.pop_back();
            }
            dq.push_back({nums[i],i});
        }
        ans.push_back(dq.front().first);
        return ans;
    }
};
