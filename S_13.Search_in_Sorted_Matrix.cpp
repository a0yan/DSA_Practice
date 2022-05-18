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
-----------------------More Optimised----------------------------------------
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0;
        if(!matrix.size()) return false;
        int hi = (matrix.size() * matrix[0].size()) - 1;
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] == target) {
                return true;
            }
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
    }
};
