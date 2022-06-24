typedef pair<int,int> ii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hm;
        priority_queue<ii,vector<ii>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            hm[nums[i]]++;
        }
        for(auto it=hm.begin();it!=hm.end();it++){
            pq.push({it->second,it->first});
        }
        vector<int>ans;
        while(k!=0){
            ii p=pq.top();
            pq.pop();
            ans.push_back(p.second);
            k--;
        }
        return ans;
    }
};
