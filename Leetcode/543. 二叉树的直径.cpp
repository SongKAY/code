/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxnum = 0;
    int maxDepth(TreeNode *root){
        if(root==NULL)
            return 0;
        int left = 0;
        int right = 0;
        left = maxDepth(root->left);
        right = maxDepth(root->right);
        maxnum = max(left+right,maxnum);
        return max(left,right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxnum;
    }
};
