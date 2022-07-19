class Solution {
public:
    vector<vector<int>>cc;
    vector<bool>stack;
    void dfs(int u,vector<vector<int>>&graph,vector<int>& disc,vector<int>& low,int& time,int parent){
        disc[u]=time;
        low[u]=time;
        time++;
        stack[u]=true;
        int child=0;
        for(int v:graph[u]){
            if(disc[v]==-1){
                // child++;
                dfs(v,graph,disc,low,time,u);
                low[u]=min(low[v],low[u]);
                
            }
            else if (v!=parent && stack[v]){
                low[u]=min(low[u],disc[v]);
            }
            if(low[v]>disc[u]){
                    cc.push_back({u,v});
                }
            
        }
        
        stack[u]=false;
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>disc(n,-1),low(n,-1);
        cc.clear();
        stack.assign(n,false);
        vector<vector<int>>graph(n);
        int time=0;
        for(auto & e:connections){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            if(disc[i]==-1){
                dfs(i,graph,disc,low,time,-1);
            }
        }
        return cc;
    }
};
