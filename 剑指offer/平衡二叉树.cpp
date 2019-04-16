class Solution {
public:
    int depth(TreeNode *root){
        if(root==NULL)
            return 0;
        int left = 0;
        int right = 0;
        left = depth(root->left) + 1;
        right = depth(root->right) + 1;
        return max(left,right);
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL)
            return true;
        int ldepth = depth(pRoot->left);
        int rdepth = depth(pRoot->right);
        if(abs(ldepth-rdepth)>1)
            return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};
