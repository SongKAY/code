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
    int result = -INT_MAX;
    int dfs(TreeNode* root){
        if(root==NULL)
            return 0;
        int left = max(0,dfs(root->left));
        int right = max(0,dfs(root->right));
        int maxx = max(left,right) + root->val;
        result = max(maxx,result);
        result = max(result,left+right+root->val);
        return maxx;
    }
    int maxPathSum(TreeNode* root) {
        int temp = dfs(root);
        return result;
    }
};
