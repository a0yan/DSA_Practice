class Solution {
public:
    void traversal(int x,int y,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(x<0 or x>=n or y<0 or y>=m or grid[x][y]!='1')
            return;
        grid[x][y]='0';
        vector<vector<int>>dir{{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<4;i++){
            int next_x=x+dir[i][0];
            int next_y=y+dir[i][1];
            traversal(next_x,next_y,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
       int count=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
                if(grid[x][y]=='1'){
                    count++;
                    traversal(x,y,grid);
                }
            }
        }
        return count;
       
    }
};
