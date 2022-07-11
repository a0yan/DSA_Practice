class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>>ans;
    void helper(int u,vector<int> adj[],vector<int>&dis,vector<int>&low,stack<int>&st,vector<bool>&instack,int &time){
        dis[u]=time;
        low[u]=time;
        st.push(u);
        instack[u]=true;
        time++;
        for(int v:adj[u]){
            if(dis[v]==-1){
                helper(v,adj,dis,low,st,instack,time);
                low[u]=min(low[u],low[v]);
            }
            else if (instack[v]==true){
                low[u]=min(low[u],dis[v]);
            }
        }
        if(low[u]==dis[u]){
            vector<int>temp;
            while(st.top()!=u){
            int node=st.top();
            st.pop();
            instack[node]=false;
            temp.push_back(node);
            }
            int node=st.top();
            st.pop();
            instack[node]=false;
            temp.push_back(node);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        
    }
    }
    vector<vector<int>> tarjans(int n, vector<int> adj[])
    {
        //code here
        ans.clear();
        vector<int>low(n,-1);
        vector<int>dis(n,-1);
        int time=0;
        stack<int>st;
        vector<bool>instack(n,false);
        for(int i=0;i<n;i++){
            if(dis[i]==-1){
                helper(i,adj,dis,low,st,instack,time);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
