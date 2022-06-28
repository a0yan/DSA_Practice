class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int ans=1;
        int start=0,end=0;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int g=0;g<n;g++){
            for(int j=g,i=0;j<n;j++,i++){
                if(g==0){
                    dp[i][j]=1;
                }
                else if (g==1){
                    if(s[i]==s[j]){
                        
                        dp[i][j]=2;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                else{
                    if(s[j]==s[i]){
                        if(dp[i+1][j-1]==j-i-1)
                        dp[i][j]=dp[i+1][j-1]+2;
                    }
                }
                if(dp[i][j]>=ans){
                            start=i;
                            end=j;
                            ans=dp[i][j];
                        }
            }
        }
        // cout<<start<<" "<<end;/
        return s.substr(start,end-start+1);
    }
};
