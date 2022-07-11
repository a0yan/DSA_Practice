#include<bits/stdc++.h>
vector<int>calIndegree(vector<vector<int>>&graph,int v){
    vector<int>degree(v,0);
    
    for(int u=0;u<v;u++){
        for(int v:graph[u]){
            degree[v]++;
        }
    }
    return degree;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>>graph(v);
    vector<int>visited(v,0);
    queue<int>q;
    int count=0;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        graph[u].push_back(v);
    }
    vector<int>degree=calIndegree(graph,v);
    for(int u=0;u<v;u++){
        if(degree[u]==0){
            q.push(u);
            visited[u]=1;
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans.push_back(u);
        count++;
        for(int v:graph[u]){
            degree[v]--;
            if(degree[v]==0 && visited[v]==0){
                q.push(v);
                visited[v]=1;
            }
        }
        
    }
    if(count==v){
        return ans;
    }
    ans.clear();
    return ans;
    
}
