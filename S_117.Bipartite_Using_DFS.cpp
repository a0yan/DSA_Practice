class Solution {
public:
    bool dfs(int u,vector<vector<int>>&graph,vector<int>&colors,int color){
        if(colors[u]!=-1 && colors[u]==color){
            return true;
        }
        if(colors[u]!=-1 && colors[u]!=color){
            return false;
        }
        colors[u]=color;
        for(int v:graph[u]){
            if(dfs(v,graph,colors,!color)==false){
                return false;
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int>colors(n,-1);
    for(int i=0;i<n;i++){
        if(colors[i]==-1){
            if(dfs(i,graph,colors,0)==false){
                return false;
            }
        }
    }
        return true;
    }
};
