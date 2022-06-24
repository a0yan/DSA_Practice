class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i=0;
        int n=heights.size();
        priority_queue<int>pq;
        // 5
     while(i<n){
         if(i==n-1){
             return i;
         }
         if(heights[i]>heights[i+1]){
             i++;
             continue;
         }
         int diff=heights[i+1]-heights[i];
         if(diff<=bricks){
             bricks-=diff;
             pq.push(diff);
             i++;
         }
         else if (ladders>0){
             if(pq.size()>0){
                 if(pq.top()>diff){
                 bricks+=pq.top();
                 bricks-=diff;
                 pq.pop();
                 pq.push(diff);
             }
             }
             
             ladders--;
            i++;
         }
         else{
             return i;
         }
     }
        return n-1;
    }
};
