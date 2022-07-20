class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>unvisited(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        if(unvisited.find(beginWord)!=unvisited.end())
        unvisited.erase(beginWord);
        int level=0;
        if(beginWord==endWord){
            return 0;
        }
        if(unvisited.find(endWord)==unvisited.end())
            return 0;
        while(!q.empty()){
            level++;
            int sz=q.size();
            while(sz--){
                string curr=q.front();
                q.pop();
                
                for(int i=0;i<curr.size();i++){
                    string temp=curr;
                    for(char c='a';c<='z';c++){
                        temp[i]=c;
                        if(temp==curr)
                            continue;
                        if(temp==endWord){
                            return level+1;
                        }
                        if(unvisited.find(temp)!=unvisited.end()){
                            q.push(temp);
                            unvisited.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
        
    }
};
