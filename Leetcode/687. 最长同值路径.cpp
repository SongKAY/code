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
    int result = 0;
    int dfs(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(root->left!=NULL&&root->left->val==root->val)
            left += 1;
        else
            left = 0;
        if(root->right!=NULL&&root->right->val==root->val)
            right += 1;
        else
            right = 0;
        result = max(result,left+right);
        return max(left,right);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL)
            return 0;
        dfs(root);
        return result;
    }
};
