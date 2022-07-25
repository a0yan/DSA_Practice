class Solution {
public:
    TreeNode* helper(TreeNode*root,TreeNode*p,TreeNode*q){
        if(!root||root==p||root==q){
            return root;
        }
        TreeNode* l=helper(root->left,p,q);
        TreeNode*r=helper(root->right,p,q);
        if(l&&r)
            return root;
        if(!l)
            return r;
        return l;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }
};
