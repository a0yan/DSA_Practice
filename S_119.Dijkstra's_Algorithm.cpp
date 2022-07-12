class Solution{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int vertices, vector<vector<int>> vec[], int source)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,source});
    vector<int>distance(vertices,INT_MAX);

    while(!pq.empty()){
        pair<int,int> node=pq.top();
        pq.pop();
        int curr_dist=node.first;
        int u=node.second;
        if(curr_dist<distance[u]){
        distance[u]=curr_dist;
       for(int i=0;i<vec[u].size();i++){
           int v=vec[u][i][0];
           int d=vec[u][i][1];
           if(distance[v]>curr_dist+d){
               pq.push({curr_dist+d,v});
           }
        }
    }
    }
    return distance;

    }
