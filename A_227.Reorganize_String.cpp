typedef pair<int,char> ic;
class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<ic>pq;
        unordered_map<int,int>mp;
        string ans="";
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->first});
        }
        
        while(pq.size()>=2){
            ic top_1=pq.top();
            pq.pop();
            ic top_2=pq.top();
            pq.pop();
            if(ans==""||ans.back()!=top_1.second){
            ans+=top_1.second;
            ans+=top_2.second;    
            }
            else{
                ans+=top_2.second;
                ans+=top_1.second;
            }
            
            top_1.first--;
            top_2.first--;
            if(top_1.first>0){
                pq.push(top_1);
            }
            if(top_2.first>0){
                pq.push(top_2);
            }
            
        }
        if(pq.size()>0){
            if(ans.back()!=pq.top().second){
                ic val=pq.top();
                ans+=val.second;
                val.first--;
                if(val.first==0)
                pq.pop();
                
            }
        }
        return pq.size()==0?ans:"";
    }
};
