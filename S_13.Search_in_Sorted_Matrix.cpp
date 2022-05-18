class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int low=matrix[i][0],high=matrix[i][m-1];
            if(target>=low and target<=high){
                int start=0,end=m-1;
                while(start<=end){
                    int mid=start+(end-start)/2;
                    if(matrix[i][mid]==target){
                        return true;
                    }
                    else if (matrix[i][mid]>target){
                        end=mid-1;
                    }
                    else{
                        start=mid+1;
                    }
                }
                return false;
            }
        }
        return false;
        
    }
};
