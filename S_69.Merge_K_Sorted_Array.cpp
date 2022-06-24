#include<bits/stdc++.h>
typedef pair<int,int> ii;
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    vector<int>indexes(k,0);
    priority_queue<ii,vector<ii>,greater<ii>>pq;
    for(int i=0;i<k;i++){
        pq.push({arr[i][0],i});
    }
    vector<int>ans;
    while(!pq.empty()){
        ii p=pq.top();
        pq.pop();
        ans.push_back(p.first);
        indexes[p.second]+=1;
        if(indexes[p.second]<arr[p.second].size()){
            pq.push({arr[p.second][indexes[p.second]],p.second});
        }
    }
    return ans;
    // Write your code here. 
}
