class Solution {
public:
    bool check_palindrome(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void helper(string s,int start,int end,vector<string>&temp,vector<vector<string>>&ans){
        if(start>end){
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<=end;i++){
            if(check_palindrome(s,start,i)){
                temp.push_back(s.substr(start,i-start+1));
                helper(s,i+1,end,temp,ans);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        int n=s.size();
        helper(s,0,n-1,temp,ans);
        return ans;
    }
};
