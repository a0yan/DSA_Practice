class Solution {
public:

void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int count,int curr,int &total)
{
    if(i>=n or j>=m or i<0 or j<0 or grid[i][j]==-1)
        return;
    
    if(grid[i][j]==2)
    {
        if(count==curr)
        {
            total++;
        }
        return;
    }
    
    grid[i][j] = -1;
    
    dfs(grid,i,j+1,n,m,count,curr+1,total);
    dfs(grid,i,j-1,n,m,count,curr+1,total);
    dfs(grid,i+1,j,n,m,count,curr+1,total);
    dfs(grid,i-1,j,n,m,count,curr+1,total);
    
    grid[i][j] = 0;
    
    return;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    
    int n = grid.size();
    int m = grid[0].size();
    
    int x,y;
    
    int count = 0; // total number of empty squares we can walk over + one final destination
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                x = i;
                y = j;
            }
            else if(grid[i][j]==0 or grid[i][j]==2)
                count++;
        }
    }
    
    int total = 0;  // total number of ways we have
    int curr = 0;   //currently how many empty squares we have passed
    dfs(grid,x,y,n,m,count,curr,total);
    return total;
}
};
