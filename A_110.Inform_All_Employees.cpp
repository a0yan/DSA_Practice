class Solution {
private:
    vector<int> t;
    vector<vector<int>> g;
    
    int DFS(int vertex)
    {
        if(!g[vertex].size()) return 0;
        
        int ans = 0;
        for(int x : g[vertex]) {
            ans = max(ans, t[vertex] + DFS(x));
        }
        return ans;
    }
    
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        g.resize(n);
        for(int i = 0 ; i < n ; ++i) {
            if(manager[i] == -1) continue;
            g[manager[i]].push_back(i);
        }
        t = informTime;
        return DFS(headID);
    }
};
