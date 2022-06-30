string smallestWindow (string s, string p)
    {
        // Your code here
        unordered_map<char,int>hm_1,hm_2;
        int len=0;
        for(int i=0;i<p.size();i++){
            hm_1[p[i]]++;
        }
        int end=0;
        int start=0;
        len=hm_1.size();
        int my_len=0;
        int size=INT_MAX;
        int t2=-1;
        while(end<s.size()){
            if(hm_1.find(s[end])!=hm_1.end()){
                hm_2[s[end]]++;
                if(hm_1[s[end]]==hm_2[s[end]]){
                    my_len++;
                }
            }
            if(my_len==len){
                while(start<=end && my_len==len){
                    if(hm_1.find(s[start])!=hm_1.end()){
                        if(hm_1[s[start]]==hm_2[s[start]]){
                            my_len--;
                        }
                        hm_2[s[start]]--;
                    }
                    start++;
                }
                if(end-start+2<size){
                    size=end-start+2;
                    t2=start-1;
                }
                
            }
            end++;
        }
        if(t2!=-1)
        return s.substr(t2,size);
        return "-1";
    }
};
