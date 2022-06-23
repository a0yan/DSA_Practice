int ceilingInSortedArray(int n, int x, vector<int> &arr){
    // Write your code here.
    int start=0;
    int end=n-1;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x){
            return x;
        }
        if(arr[mid]>x){
            ans=arr[mid];
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}
