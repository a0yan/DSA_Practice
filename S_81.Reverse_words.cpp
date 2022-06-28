class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans="";
        stack <string> st;
        while(getline(ss,word,' ')){
            if(word[0]!='\0'){
            st.push(word);
            // cout<<"->"<<word<<"<-"<<endl;
            }
            
        }
        while(!st.empty()){
            ans+=st.top()+" ";
            st.pop();
        }
        int n=ans.size();
        return ans.substr(0,n-1);
        
    }
};
