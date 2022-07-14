class Solution {
public:
    void dfs(int u,vector<vector<int>>&graph,vector<int>&visited,int&size){
        visited[u]=1;
        size++;
        for(int v:graph[u]){
            if(!visited[v]){
                dfs(v,graph,visited,size);
            }
            
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>>graph(n);
        int cables=connections.size();
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int components=0;
        int extra=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            int size=0;
            if(!visited[i]){
                components++;
                dfs(i,graph,visited,size);
                extra+=size-1;
            }
        }
        int required=components-1;
        int surplus=cables-extra;
        if(required<=surplus){
            return required;
        }
        return -1;
        
    }
};
