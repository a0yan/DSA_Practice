void helper(vector<int> arr, int n,int total,vector<int>&ans){
        if(n==0){
            ans.push_back(total);
            return;
        }
        helper(arr,n-1,total,ans);
        helper(arr,n-1,total+arr[n-1],ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        int total=0;
        helper(arr,N,total,ans);
        return ans;
    }
};
