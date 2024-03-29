class NumMatrix {
public:
    vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        dp.assign(n,vector<int>(m,0));
        dp[0][0]=matrix[0][0];
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0]+matrix[i][0];
        }
        for(int j=1;j<m;j++){
            dp[0][j]=dp[0][j-1]+matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+matrix[i][j]-dp[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=dp[row2][col2];
        if(row1-1>=0){
            ans-=dp[row1-1][col2];
        }
        if(col1-1>=0){
            ans-=dp[row2][col1-1];
        }
        if(row1-1>=0 and col1-1>=0){
            ans+=dp[row1-1][col1-1];
        }
        return ans;
    }
};

