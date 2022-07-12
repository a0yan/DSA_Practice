#include<bits/stdc++.h>
class Node {
    public:
        int u,v,wt;
        Node(int a,int b,int c){
            u=a;
            v=b;
            wt=c;
        }
};
bool compare(Node&a,Node&b){
    return a.wt<b.wt;
}
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	void dsu(int n,vector<int>&parent,vector<int>&size){
	    parent.assign(n,-1);
	    size.assign(n,0);
	    for(int i=0;i<n;i++){
	        parent[i]=i;
	    }
	}
	int find(int x,vector<int>& parent){
	    if(parent[x]==x){
	        return x;
	    }
	    return parent[x]=find(parent[x],parent);
	}
	void join(int x,int y,vector<int>&parent,vector<int>&size){
	    int p_x=find(x,parent);
	    int p_y=find(y,parent);
	    if (p_x != p_y) {
        if (size[p_x] < size[p_y])
            swap(p_x, p_y);
        parent[p_y] = p_x;
        size[p_x] += size[p_y];
    }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<Node>edges;
        vector<int>parent,size;
        dsu(V,parent,size);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                int v=adj[i][j][0];
                int d=adj[i][j][1];
                edges.push_back({i,v,d});
            }
            }
            int c=0;
        sort(edges.begin(),edges.end(),compare);
        for(int i=0;i<edges.size();i++){
            int u=edges[i].u;
            int v=edges[i].v;
            int wt=edges[i].wt;
            if(find(u,parent)!=find(v,parent)){
                join(u,v,parent,size);
                c+=wt;
            }
    }
    return c;
    }
    
    
};
