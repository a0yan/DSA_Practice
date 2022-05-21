class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                for(int k=0;k<dir.size();k++){
                    int x=i+dir[k][0];
                    int y=j+dir[k][1];
                    if(x>=0 and x<n and y>=0 and y<m){
                        if(board[x][y]==1||board[x][y]==2){
                            count++;
                        }
                    }
                }
                if(board[i][j]==1 && (count<2 || count>3)){
                    board[i][j]=2;
                }
                else if (board[i][j]==0 && count==3){
                    board[i][j]=-1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==2){
                    board[i][j]=0;
                }
                else if(board[i][j]==-1){
                    board[i][j]=1;
                }
            }
        }
    }
};
