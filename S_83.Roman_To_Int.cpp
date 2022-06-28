class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>hm{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int n=s.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(hm[s[i]]<hm[s[i+1]]){
                ans-=hm[s[i]];
            }
            else{
                ans+=hm[s[i]];
            }
        }
        ans+=hm[s[n-1]];
        return ans;
    }
};
