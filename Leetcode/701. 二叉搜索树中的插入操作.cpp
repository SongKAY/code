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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            root = new TreeNode(val);
            return root;
        }
        if(root->val<val){
            TreeNode* node = insertIntoBST(root->right,val);
            if(root->right==NULL)
                root->right = node;
        }
        else{
            TreeNode* node = insertIntoBST(root->left,val);
            if(root->left==NULL)
                root->left = node;
        }
        return root;
    }
};
