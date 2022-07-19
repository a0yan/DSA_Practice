class Solution{
    public:
    unordered_map<char,vector<char>>graph;
    void find_mismatch(string a,string b){
        int n=a.size();
        int m=b.size();
        int i=0,j=0;
        while(i<n and j<m){
            if(a[i]!=b[j]){
                graph[a[i]].push_back(b[j]);
                break;
            }
            i++;
            j++;
        }
    }
    void dfs(char u,unordered_map<char,vector<char>>&graph,unordered_set<char>&visited,string& st){
        visited.insert(u);
        for(char v:graph[u]){
            if(visited.find(v)==visited.end()){
                dfs(v,graph,visited,st);
            }
        }
        st+=u;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        graph.clear();
        for(int i=0;i<N-1;i++){
            find_mismatch(dict[i],dict[i+1]);
        }
        unordered_set<char>visited;
        string st;
        for(char c='a';c<='z';c++){
            if(!visited.count(c)){
                dfs(c,graph,visited,st);
            }
        }
        reverse(st.begin(),st.end());
        return st;
        
        
        
    }
};
