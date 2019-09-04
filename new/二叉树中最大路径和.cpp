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
    int result = -999999999;
    int dfs(TreeNode *root){
        if(root==NULL)
            return 0;
        int left  = max(dfs(root->left),0);
        int right = max(dfs(root->right),0);
        result = max(left+right+root->val,result);
        int maxx = max(left,right)+root->val;
        result = max(maxx,result);
        return maxx;
    }
    int maxPathSum(TreeNode* root) {
        int temp = dfs(root);
        return result;
    }
};
