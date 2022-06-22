bool helper(vector<vector<int>>& maze, int x,int y,string& solution,vector<string>&ans){
    int n=maze.size();
    if(x==n-1 and y==n-1){
//         cout<<"Called"<<" "
    ans.push_back(solution);
        return true;
    }
    if(maze[x][y]==0)
    return false;
    maze[x][y]=0;
    bool possible=false;
    vector<vector<int>>dir{{0,1},{1,0},{-1,0},{0,-1}};
    for(int i=0;i<4;i++){
        int new_x=x+dir[i][0];
        int new_y=y+dir[i][1];
        if(new_x>=0 and new_x<n and new_y>=0 and new_y<n and maze[new_x][new_y]==1){
//             cout<<"Called"<<endl;
            if(i==0)
            solution+='R';
            else if(i==1)
            solution+='D';
            else if(i==2)
            solution+='U';
            else
            solution+='L';
            helper(maze,new_x,new_y,solution,ans);
            solution.pop_back();
                
        }
    }
    maze[x][y]=1;
    return true;
    
}
class Solution{
    public:
    
    vector<string> ratInAMaze(vector<vector<int> > &maze, int n){
      // Write your code here.
        string solution="";
        vector<string>ans;
        helper(maze,0,0,solution,ans);
        return ans;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        return ratInAMaze(m,n);
    }
};
