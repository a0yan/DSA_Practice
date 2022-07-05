class Solution {
public:
    int setbits(int n){
        int count=0;
        while(n){
            count+=n&1;
            n=n>>1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        ans[0]=0;
        if(n==0){
            return ans;
        }
        ans[1]=1;
        if(n==1){
            return ans;
        }
        ans[2]=1;
        for(int i=3;i<=n;i++){
            if(i%2==0){
                ans[i]=ans[i>>1];
            }
            else{
                ans[i]=ans[i>>1]+1;
            }
        }
        return ans;
    }
};
// --> 0 1 1 2 1 2 2 3 1 2 2 3
