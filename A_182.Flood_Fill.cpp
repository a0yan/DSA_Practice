typedef pair<int,int> ii;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& matrix, int sr, int sc, int color) {
     queue<ii>q;
     int n=matrix.size();
     int m=matrix[0].size();
        q.push({sr,sc});
        int c_col=matrix[sr][sc];
        if(c_col==color){
            return matrix;
        }
        while(!q.empty()){
            int x,y;
            x=q.front().first;
            y=q.front().second;
            q.pop();
            // cout<<x<<y<<endl;
            // c_col=matrix[x][y];
            matrix[x][y]=color;
            vector<ii>dir{{0,1},{1,0},{-1,0},{0,-1}};
            for(int i=0;i<4;i++){
                int next_x=x+dir[i].first;
                int next_y=y+dir[i].second;
                if(next_x<0 ||next_y<0 || next_y>=m ||next_x>=n||matrix[next_x][next_y]!=c_col)
                    continue;
                // cout<<next_x<<next_y<<endl;
                q.push({next_x,next_y});
            }
        }
        return matrix;
    }
};
