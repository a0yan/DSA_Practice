class Solution {
public:
    int calc(vector<int>& cuts,map<pair<int,int>,int>& mpp, int i ,int j){
        if(i>=j)return 0;
        int mn=1e7;
        if(mpp.find({i,j})!=mpp.end())return mpp[{i,j}];
        
        for(auto k:cuts){
            if(k<=i || k>=j)continue;
            int val=j-i+calc(cuts,mpp,i,k)+calc(cuts,mpp,k,j);
            mn=min(mn,val);
        }
        return mpp[{i,j}]= mn<1e7?mn:0;
    }
    int minCost(int n, vector<int>& cuts) {
        map<pair<int,int>,int> mpp;
        return calc(cuts,mpp, 0,n);
    }
};
