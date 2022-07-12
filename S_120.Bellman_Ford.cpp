class Solution{
	public:
	
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> distance(V, 1e8);
        
        distance[S] = 0;
        
        for(int i=0; i<V-1; i++){
            for(vector<int> edge : adj){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                distance[v] = min(distance[v], distance[u]+w);
            }
        }
        
        return distance;
    }
};
