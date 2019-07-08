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
    void dfs(TreeNode* root, int temp){
        if(root==NULL)
            return;
        else if(root->left==NULL&&root->right==NULL){
            result += temp*10 + root->val;
            return;
        }
        dfs(root->left,temp*10+root->val);
        dfs(root->right,temp*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return result;
        dfs(root,0);
        return result;
    }
};
