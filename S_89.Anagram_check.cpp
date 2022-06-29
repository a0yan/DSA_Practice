class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>hm;
        for(int i=0;i<s.size();i++){
            hm[s[i]]++;
        }
        for(int j=0;j<t.size();j++){
            if(hm.find(t[j])==hm.end()){
                return false;
            }
            hm[t[j]]--;
            if(hm[t[j]]==0){
                hm.erase(t[j]);
            }
        }
        return hm.empty();
    }
};
