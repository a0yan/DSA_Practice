class Solution {
public:
    bool isvalid(string str){
        if(str.size()==0||str[0]=='0')
            return false;
        if(str.size()>2)
            return false;
        int val=stoi(str);
        if(val>=1 and val<=26){
            return true;
        }
        return false;
    }
    int helper(int index,string& s,vector<int>&dp){
        int n=s.size();
        if(index==n){
            return 1;
        }
        if(index>n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int ways=0;
        for(int k=1;k<=2;k++){
            if(isvalid(s.substr(index,k))){
                ways+=helper(index+k,s,dp);
            }
        }
        return dp[index]=ways;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        for(int index=n;index>=0;index--){
            if(index==n){
                dp[index]=1;
            }
            else{
        int ways=0;
        for(int k=1;k<=2&&index+k<=n;k++){
            if(isvalid(s.substr(index,k))){
                ways+=dp[index+k];
            }
        }
        dp[index]=ways;
            }
            
        }
        return dp[0];
        // return helper(0,s,dp);
    }
};
