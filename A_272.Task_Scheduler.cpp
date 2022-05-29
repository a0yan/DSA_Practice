class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26];
        fill(cnt, cnt + 26, 0);
        for (char c : tasks) {
            ++cnt[c - 'A'];
        }
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0) pq.push(cnt[i]);
        }
        int time = 1;
        while(!pq.empty() || !q.empty()){
            if(!q.empty()){
                if(q.front().second<=time){
                    pq.push(q.front().first);
                    q.pop();
                }
            }
            if(!pq.empty()){
                int count=pq.top();
                pq.pop();
                count--;
                if(count>0){
                    q.push({count,time+n+1});
                }
            }
            time++;
        }
        return time-1;
    }
    
};
