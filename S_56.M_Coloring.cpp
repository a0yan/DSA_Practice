bool validColor(int node,int color,vector<int>&colors,vector<vector<int>>&matrix){
    for(int i=0;i<matrix.size();i++){
        int adj=matrix[node][i];
        if(adj==1 and colors[i]==color)
            return false;
    }
    return true;
}
bool helper(vector<vector<int>> &mat, int index, int m,vector<int>& colors){
    int n=mat.size();
    if(index==n){
        return true;
    }
    for(int col=0;col<m;col++){
        if(validColor(index,col,colors,mat)){
            colors[index]=col;
            if(helper(mat,index+1,m,colors)==true){
                return true;
            }
            else{
                colors[index]=-1;
            }
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n=mat.size();
    vector<int>colors(n,-1);
    if(helper(mat,0,m,colors)){
        return "YES";
    }
    return "NO";
}
