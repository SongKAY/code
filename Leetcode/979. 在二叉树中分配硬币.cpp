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
    int ans = 0;
    int dfs(TreeNode* root){
        if(root==NULL)
            return 0;
        int tmp = root->val;
        tmp += dfs(root->left) + dfs(root->right);
        ans += abs(tmp - 1);
        return tmp-1;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
