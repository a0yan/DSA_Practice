class Solution {
public:
    bool possible(vector<string>&matrix,int x,int y){
        int n=matrix.size();
        for(int row=0;row<n;row++){
            if(matrix[row][y]=='Q')
                return false;
        }
        for(int col=0;col<n;col++){
            if(matrix[x][col]=='Q')
                return false;
        }
        int i=x,j=y;
        while(i<n and j<n){
            if(matrix[i][j]=='Q')
                return false;
            i++;
            j++;
        }
        i=x,j=y;
        while(i>=0 and j>=0){
            if(matrix[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        i=x,j=y;
        while(i>=0 and j<n){
            if(matrix[i][j]=='Q')
                return false;
            i--;
            j++;
        }
        i=x,j=y;
        while(i<n and j>=0){
            if(matrix[i][j]=='Q')
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool helper(int index,vector<string>&matrix,vector<vector<string>>&ans){
        int n=matrix.size();
        if(index==n){
            ans.push_back(matrix);
            return true;
        }
        for(int j=0;j<n;j++){
            // cout<<matrix[index][j]<<" ";
            if(possible(matrix,index,j)){
                // cout<<"Called"<<" ";
                matrix[index][j]='Q';
                helper(index+1,matrix,ans);
                matrix[index][j]='.';
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>matrix(n,string(n,'.'));
        vector<vector<string>>ans;
        helper(0,matrix,ans);
        return ans;
    }
};
