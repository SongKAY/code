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
    int sum(TreeNode* root){
        if(root==NULL)
            return 0;
        int left = 0;
        int right = 0;
        if(root->left!=NULL)
            left =  sum(root->left);
        if(root->right!=NULL)
            right = sum(root->right); 
        result += abs(right-left);
        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        if(root==NULL)
            return 0;
        int left = 0;
        int right = 0;
        if(root->left!=NULL)
            left = sum(root->left);
        if(root->right!=NULL)
            right = sum(root->right);
        result += abs(left-right);
        return result;
    }
};
