class Solution {
public:
    vector<int> LPS_FUN(string pat){
        int n=pat.size();
        vector<int>lps(n,0);
        lps[0]=0;
        int len=0;
        int i=1;
        while(i<n){
            if(pat[i]==pat[len]){
                lps[i]=len+1;
                len++;
                i++;
            }
            else if (len>0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                len=0;
                i++;
            }
        }
        return lps;
    }
    int patternMatching(string str,string pat){
        vector<int>lps=LPS_FUN(pat);
        int i=0,j=0;
        int m=pat.size();
        int n=str.size();
        while(i<n){
            if(str[i]==pat[j]){
                i++;
                j++;
                
            }
            if(j==m){
                return i-j;
            }
            else if(i<n and str[i]!=pat[j]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
            
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        return(patternMatching(haystack,needle));
    }
};
