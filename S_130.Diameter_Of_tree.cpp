class Solution {
public:
    int helper(TreeNode* root,int& diameter){
        if(!root)
            return 0;
        int l_height=helper(root->left,diameter);
        int r_height=helper(root->right,diameter);
        diameter=max(diameter,l_height+r_height+1);
        return 1+max(l_height,r_height);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root||(root->left==NULL and root->right==NULL))
            return 0;
        int diameter=0;
        helper(root,diameter);
        return diameter-1;
    }
};
