class Solution {
public:
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }
        if(!root->left and !root->right){
            return 1;
        }
        return 1+max(helper(root->left),helper(root->right));
    }
    int maxDepth(TreeNode* root) {
        return helper(root);
    }
};
