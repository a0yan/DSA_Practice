#include <bits/stdc++.h>  
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
int minCharsforPalindrome(string str) {
	// Write your code here.
    string temp=str;
    int n=str.size();
    reverse(str.begin(),str.end());
    temp+='#'+str;
    return n-LPS_FUN(temp)[temp.size()-1];
	
}
