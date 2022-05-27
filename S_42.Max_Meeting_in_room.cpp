static bool comp(pair<int,int>&a,pair<int,int>&b){
        if(a.second==b.second){
            return a.first>b.first; 
        }
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        // stack<pair<int,int>>st;
        vector<pair<int,int>>meet;
        for(int i=0;i<n;i++){
            meet.push_back({start[i],end[i]});
        }
        sort(meet.begin(),meet.end(),comp);
        int last=meet[0].second;
        int c=1;
        for(int i=0;i<n;i++){
            if(last<meet[i].first){
                c++;
                last=meet[i].second;
            }
        }
        return c;
        
        
    }
