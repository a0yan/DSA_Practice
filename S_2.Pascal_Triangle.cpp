class Solution {
public:
    vector<int>helper(int n,vector<vector<int>>& matrix){
        vector<int>temp;
        temp.push_back(1);
        if(n==1){
            matrix.push_back(temp);
            return temp;
        }
        vector<int> prev_row=helper(n-1,matrix);
        for(int i=1;i<prev_row.size();i++){
            temp.push_back(prev_row[i]+prev_row[i-1]);
        }
        temp.push_back(1);
        matrix.push_back(temp);
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> matrix;
        helper(numRows,matrix);
        return matrix;
    }
};
