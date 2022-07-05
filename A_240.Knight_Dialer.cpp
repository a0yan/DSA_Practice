class Solution {
public:
    int dp[4][3][5001];
    int mod = 1e9+7;
    
    int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    
    bool isSafe(vector<vector<int>> &grid, int &row, int &col) {
        return row >= 0 && row < 4 && col >= 0 && col < 3 && grid[row][col] != -1;
    }
    
    int solve(vector<vector<int>> &grid, int row, int col, int n) {
        if(n == 1) return 1;
        if(dp[row][col][n] != -1) return dp[row][col][n];
        long long ans = 0;
        for(int i=0; i<8; i++) {
            int x = row + dx[i];
            int y = col + dy[i];
            if(isSafe(grid, x, y)) {
                ans += solve(grid, x, y, n-1) % mod;
            }
        }
        return dp[row][col][n] = ans % mod;
    }
    
    int knightDialer(int n) {
        long long ans = 0, k = 1;
        vector<vector<int>> grid(4, vector<int> (3, 0));
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                grid[i][j] = k++;
            }
        }
        grid[3][1] = 0;
        grid[3][0] = grid[3][2] = -1;
        /////////
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<4; i++) {
            for(int j=0; j<3; j++) {
                if(grid[i][j] != -1) {
                    ans += solve(grid, i, j, n) % mod;
                }
            }
        }
        return ans % mod;
    }
};
