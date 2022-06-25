class Compare{
    public:
    bool operator()(vector<int>&a,vector<int>&b){
        return a[1]<=b[1];
    }
};
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int,vector<int>>pq;
        int n=stations.size();
        if(startFuel>=target){
            return 0;
        }
        int current=startFuel;
        int stops=0;
        int i=0;
        // stations.push_back({target,INT_MAX});
        while(current<target){
            while(i<n and stations[i][0]<=current){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()){
                return -1;
            }
            int curr=pq.top();
            pq.pop();
            current+=curr;
            stops++;
            
        }
        
        return stops;
        
    }
};
