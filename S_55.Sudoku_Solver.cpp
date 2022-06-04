class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(char c='1'; c<='9'; c++){
                        if(valid(c, board, i, j)){
                            board[i][j] = c;
                            if(solve(board) == true) return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool valid(char c, vector<vector<char>>& board, int row, int col){
        for(int i=0; i<9; i++){
            if(board[i][col] == c) return false;
            if(board[row][i] == c) return false;
        }
        int start_x=row-row%3;
            int start_y=col-col%3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[start_x+i][start_y+j]==c)
                    return false;
            }
        }
        return true;
    }
};
