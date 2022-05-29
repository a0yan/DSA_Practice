class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        string ans;
        ans.push_back(colors[0]);
        
        int n=colors.size();
        int back=0;
        int minTime=0;
        
        for(int i=1;i<n;i++){
            if(ans.back()==colors[i]){
                if(neededTime[back]<neededTime[i]) {
                    minTime+=neededTime[back];
                    back=i;
                }
                else minTime+=neededTime[i];          
            }
            else {
                ans+=colors[i];
                back=i;
            }
            
        }

        return minTime;
    }
};
