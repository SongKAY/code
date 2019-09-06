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
    int flag = 0;
    void dfs(TreeNode* root,int temp,int sum){
        if(flag)
            return;
        if(root->left==NULL&&root->right==NULL){
            if(temp+root->val==sum){
                flag = 1;
            }
            return;
        }
        if(root->left!=NULL)
            dfs(root->left,temp+root->val,sum);
        if(root->right!=NULL)
            dfs(root->right,temp+root->val,sum);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        dfs(root,0,sum);
        if(flag)
            return true;
        return false;
    }
};
