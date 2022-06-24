int count_pos(vector<vector<int>> &arr, int n,int m, int digit)
{
    int c = 0;
    for(int i = 0; i < n; i++)
    {
        int s = 0, e = m-1,ans=-1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(arr[i][mid]>digit)
            {
                ans=mid; 
                e = mid - 1;
            }
            else if (arr[i][mid]==digit){
                ans=mid+1;
                s=mid+1;
            }
            else
            {
                s=mid+1;
            }
        }
        if(ans>=0)
            c += ans;
        else
            c+=m;
    }
    return c;
}
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int mx=INT_MIN;
        int mn=INT_MAX;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]>mx){
                    mx=matrix[i][j];
                }
                if(matrix[i][j]<mn){
                    mn=matrix[i][j];
                }
            }
        }
        int start=mn;
        int end=mx;
        int ans=mx;
        while(start<=end){
            int target=start+(end-start)/2;
            int count=count_pos(matrix,n,n,target);
            if(count>=k){
                ans=target;
                end=target-1;
            }
            else{
                start=target+1;
            }
        }
        return ans;
    }
};
