typedef pair<TreeNode*,int> ii;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<ii> q;
        q.push({root,0});
        int ans=0,start=0,end=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode *node=q.front().first;
                int col_level=q.front().second;
                q.pop();
                if(i==0){
                    start=col_level;
                }
                if(i==n-1){
                    end=col_level;
                    ans=max(ans,abs(end-start+1));
                }
                if(node->left){
                    q.push({node->left,col_level*2LL+1});
                }
                if(node->right){
                    q.push({node->right,col_level*2LL+2});
                }
            }
        }
        return ans;
    }
};
