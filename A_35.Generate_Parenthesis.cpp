class Solution {
public:
    void brackets(int o,int c,string s,vector<string>& ans){
        if(c<o){
            return;
        }
        if(o==0 && c==0){
            ans.push_back(s);
            return;
        }
        
        if(o>0){
            brackets(o-1,c,s+'(',ans);
        }
        if(o<c)      
        brackets(o,c-1,s+')',ans);
        
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        brackets(n,n,"",ans);
        return ans;
    }
};
