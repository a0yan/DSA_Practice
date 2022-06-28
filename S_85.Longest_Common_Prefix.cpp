class Solution {
public:
    string common(string&s1,string&s2){
        if(s1==""||s2==""){
            return "";
        }
        int n=s1.size();
        int m=s2.size();
        string ans="";
        for(int i=0;i<min(n,m);i++){
            if(s1[i]==s2[i]){
                ans+=s1[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        if(strs.size()==1){
            return strs[0];
        }
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++){
            prefix=common(prefix,strs[i]);
        }
        return prefix;
    }
};
