class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void reverse(vector<vector<int>>& matrix){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            int start=0;
            int end=n-1;
            while(start<end){
                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse(matrix);
    }
};
