class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>st;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            if(st.size()!=0 && st.back()[1]>=intervals[i][0]){
             st.back()[0]=min(st.back()[0],intervals[i][0]);
                st.back()[1]=max(st.back()[1],intervals[i][1]);
            }
            else{
                st.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        return st;
    }
};
