class Solution {
public:
    bool checkbeautiful(vector<int>arr){
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]%(i+1)==0 || (i+1)%arr[i]==0)
                continue;
            return false;
        }
        return true;
    }
    int helper(int index,vector<int>arr){
        int n=arr.size();
        if(index==n){
            return 1;
        }
        int c=0;
        for(int i=index;i<n;i++){
            if(arr[i]%(index+1)==0 || (index+1)%arr[i]==0){
            swap(arr[i],arr[index]);
            c+=helper(index+1,arr);
            swap(arr[i],arr[index]);    
            }
            
        }
        return c;
    }
    int countArrangement(int n) {
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        return helper(0,arr);
    }
};
