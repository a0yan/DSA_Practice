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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int area=0;
        int m=matrix[0].size();
        int n=matrix.size();
        vector<int>temp(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(i==0){
                temp[j]=matrix[i][j]-'0';
            }
            else{
                if(matrix[i-1][j]=='1'&& matrix[i][j]=='1'){
                    temp[j]+=1;
                }
                else if(matrix[i][j]=='1'){
                    temp[j]=1;
                }
                else{
                    temp[j]=0;
                }
            }
            }
            int val=largestRectangleArea(temp);
            // cout<<temp[0]<<" "<<temp[1]<<" ";
            area=max(area,val);
        }
        return area;
    }
};
// 0  1

// 1
// 4 1 2 2 2
