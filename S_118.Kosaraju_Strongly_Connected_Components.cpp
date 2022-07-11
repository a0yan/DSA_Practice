
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int u,vector<int> adj[],stack<int>&st,vector<bool>& visited){
	    visited[u]=true;
	    for(int v:adj[u]){
	        if(!visited[v]){
	            dfs(v,adj,st,visited);
	        }
	    }
	    st.push(u);
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool>visited(V,false);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,st,visited);
            }
        }
        vector<int>copy_graph [V];
        for(int u=0;u<V;u++){
            for(int v:adj[u]){
                copy_graph[v].push_back(u);
        }
        }
        int count=0;
        stack<int>new_st;
        visited.assign(V,false);
        while(!st.empty()){
            int u=st.top();
            st.pop();
            // cout<<u<<"-->";
            if(!visited[u]){
                count++;
                dfs(u,copy_graph,new_st,visited);
                
                
            }
        }
        return count;
        //code here
    }
};
