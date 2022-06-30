class Solution {
public:
    string simplifyPath(string path) {
        vector<string>seperated;
        stringstream ss(path);
        string word;
        while(getline(ss,word,'/')){
            if(word[0]!='\0'){
            if(word==".")continue;
            if(word==".." and seperated.size()>0){
                seperated.pop_back();
            }
            else if (word!="..")
            seperated.push_back(word);
            }
        }
        string ans="/";
        for(string& word:seperated){
            ans+=word+'/';
        }
        if(ans.size()>1)
        return ans.substr(0,ans.size()-1);
        return ans;
    }
};
