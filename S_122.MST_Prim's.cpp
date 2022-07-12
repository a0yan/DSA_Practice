typedef pair<int,int> ii;
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int c=0;
        priority_queue<ii,vector<ii>,greater<ii>>pq;
        pq.push({0,0});
        vector<bool>visited(V,false);
        while(!pq.empty()){
            ii node=pq.top();
            pq.pop();
            int u=node.second;
            int dist=node.first;
            if(visited[u]==false){
                c+=dist;
                visited[u]=true;
                for(int i=0;i<adj[u].size();i++){
                    int v=adj[u][i][0];
                    int d=adj[u][i][1];
                    pq.push({d,v});
                }
            }
        
    }
    return c;
    }
};
