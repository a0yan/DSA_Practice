typedef pair<int,int> ii;
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<ii> pq;
        int ans=INT_MIN;
        int n=points.size();
        for(int j=0;j<n;j++){
            while(!pq.empty() && pq.top().second<points[j][0]-k){
                pq.pop();
            }
            if(!pq.empty()){
                ans=max(ans,pq.top().first+points[j][0]+points[j][1]);
            }
            pq.push({points[j][1]-points[j][0],points[j][0]});
        }
        return ans;
        
    }
};
------------------More Optimised Soln----------------
typedef pair<int,int> ii;
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<ii> dq;
        int ans=INT_MIN;
        int n=points.size();
        for(int j=0;j<n;j++){
            while(!dq.empty() && dq.front().second<points[j][0]-k){
                dq.pop_front();
            }
            if(!dq.empty()){
                ans=max(ans,dq.front().first+points[j][0]+points[j][1]);
            }
            while(!dq.empty() && dq.back().first<=points[j][1]-points[j][0]){
                dq.pop_back();
            }
            dq.push_back({points[j][1]-points[j][0],points[j][0]});
        }
        return ans;
        
    }
};
  
