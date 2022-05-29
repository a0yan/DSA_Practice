class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> result;
    unordered_map<int,vector<int>> key;
    for(auto a:adjacentPairs){
        key[a[0]].push_back(a[1]);
        key[a[1]].push_back(a[0]);
    }
    int s;
    for(auto a:key) if(a.second.size()==1){s=a.first; break;}
    set<int>visited;
    visited.insert(s);
    result.push_back(s);
    while(visited.size()!=key.size()){
        if(visited.count(key[s][0]))
            s=key[s][1];
        else
            s=key[s][0];
        visited.insert(s);
        result.push_back(s);
    }
    return result;
}
        
    };
//1-2
//2-(1,3)
//3-(2,4)
