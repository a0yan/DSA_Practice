class Solution {
public:
    int helper(TreeNode* root){
        if(!root)
            return 0;
        int l=helper(root->left);
        int r=helper(root->right);
        if(l==-1||r==-1)
            return -1;
        if(abs(l-r)<=1)
            return max(l,r)+1;
        return -1;
    }
    bool isBalanced(TreeNode* root) {
        if(helper(root)==-1)
            return false;
        return true;
    }
};
