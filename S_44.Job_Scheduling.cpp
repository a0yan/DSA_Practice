#include<bits/stdc++.h>
using namespace std;
bool comp (vector<int>&a,vector<int>&b){
    if(a[1]==b[1]){
        return a[0]<=b[0];
    }
    return a[1]>b[1];
}
vector<int> make_disjoint_set(int n){
    vector<int>parent(n,0);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    return parent;
}
int find(int u,vector<int>& parent){
    if(parent[u]==u){
        return u;
    }
    return parent[u]=find(parent[u],parent);
   
}
void make_union (int u,int v,vector<int> &parent){
    parent[v]=u;
//     cout<<v<<u<<parent[v]<<endl;
    return;
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n=jobs.size();
    int ans=0;
    sort(jobs.begin(),jobs.end(),comp);
    int mx=0;
    for(int i=0;i<n;i++)
        mx=max(mx,jobs[i][0]);

vector<int> parent=make_disjoint_set(mx+1);
for(int i=0;i<n;i++){
    int avai=find(jobs[i][0],parent);
//     cout<<avai<<" ";
    if(avai>0){
        ans+=jobs[i][1];
       
        int v2=find(avai-1,parent);
        make_union(v2,avai,parent);
//         cout<<parent[1]<<" ";
    }
}
    
    return ans;
}
----------O(n2)-----------
// int jobScheduling(vector<vector<int>> &jobs)
// {
//     // Write your code here
//     vector<int>time(30001,-1);
//     int n=jobs.size();
//     int ans=0;
//     sort(jobs.begin(),jobs.end(),comp);
//     int profit=0;
//     for(int i=0;i<n;i++){
//         for(int j=jobs[i][0]-1;j>=0;j--){
//             if(time[j]==-1){
//                 time[j]=jobs[i][1];
//                 ans+=time[j];
//                 break;
//             }
//         }
//     }
//     return ans;
// }
