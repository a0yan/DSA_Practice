typedef pair<Node*,int> pi;
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int>mp;
        queue<pi>q;
        vector<int>ans;
        if(!root){
            return ans;
        }
        q.push({root,0});
        
        while(!q.empty()){
            int dist=q.front().second;
            Node* node=q.front().first;
            q.pop();
            mp[dist]=node->data;
            if(node->left){
                q.push({node->left,dist-1});
            }
            if(node->right){
                q.push({node->right,dist+1});
            }
        
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        ans.push_back(it->second);
    }
    return ans;
    }
};
