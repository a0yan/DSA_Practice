class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_gas =0;
        int prev_gas =0;
        int start =0;
        for(int i=0;i<gas.size();i++){
            curr_gas+= gas[i]-cost[i];
            if(curr_gas<0){
                start=i+1;
                prev_gas+=curr_gas;
                curr_gas=0;
            }
        }
        if(curr_gas+prev_gas >=0){
            return start;
        }
        return -1;
    }

};
