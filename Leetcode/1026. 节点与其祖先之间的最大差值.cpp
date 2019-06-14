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
    int maxAncestorDiff(TreeNode* root) {
        int result = 0;
        if(root)
            maxdiff(root,root->val,root->val,result);
        return result;
    }
    
    void maxdiff(TreeNode* root,int low,int high, int &result){
        result = max(abs(root->val-low),result);
        result = max(abs(root->val-high),result);
        low = min(low,root->val);
        high = max(high,root->val);
        if(root->left)
            maxdiff(root->left,low,high,result);
        if(root->right)
            maxdiff(root->right,low,high,result);
    }
};
