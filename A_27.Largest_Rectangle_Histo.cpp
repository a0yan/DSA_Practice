class Solution {
public:
    vector<int> preSmaller(vector<int>& heights){
        vector<int>pre;
        stack<int>st;
        int n=heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()]>=heights[i] ){
                st.pop();
            }
            if(st.empty()){
                pre.push_back(-1);
            }
            else{
                pre.push_back(st.top());
            }
            st.push(i);
        }
        return pre;
    }
    vector<int> nexSmaller(vector<int>& heights){
        vector<int>nex;
        stack<int>st;
        int n=heights.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and heights[st.top()]>=heights[i] ){
                st.pop();
            }
            if(st.empty()){
                nex.push_back(n);
            }
            else{
                nex.push_back(st.top());
            }
            st.push(i);
        }
        reverse(nex.begin(),nex.end());
        return nex;
    }
    int largestRectangleArea(vector<int>& heights) {
        int ma=0;
        int n=heights.size();
        vector<int>nex,pre;
        nex=nexSmaller(heights);
        pre=preSmaller(heights);
        for(int i=0;i<n;i++){
            int area=heights[i]*(nex[i]-pre[i]-1);
            ma=max(area,ma);
        }
        return ma;
        
    }
};
----------------Optimised Solution---------------
 class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int max_area=0;
        int n=heights.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n||heights[st.top()]>=heights[i])){
                int block=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
                max_area=max(max_area,width*block);
            }
            st.push(i);
        }
        return max_area;
    }
};
