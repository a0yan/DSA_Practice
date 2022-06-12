class Solution{
  public:
    bool helper(int index, int a[],int n,int k,int total,int target,vector<int>visited){
        if(k==0){
            return true;
        }
        if(total==target){
            return helper(0,a,n,k-1,0,target,visited);
        }
        if(total>target){
            return false;
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                visited[i]=1;
                if(helper(i+1,a,n,k,total+a[i],target,visited)){
                    return true;
                }
                visited[i]=0;
            }
        }
        return false;
        
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum=0;
         for(int i=0;i<n;i++)
         sum+=a[i];
         if(sum%k!=0){
             return false;
         }
         vector<int>visited(n,0);
         return helper(0,a,n,k,0,sum/k,visited);
         
    }
};
