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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return root;
        if(root->val==key){
            if(root->left){
                TreeNode *node = root->left;
                while(node->right){
                    node = node->right;
                }
                node->right = root->right;
                return root->left;
            }
            else if(root->right){
                TreeNode *node = root->right;
                while(node->left){
                    node = node -> left;
                }
                node->left = root->left;
                return root->right;
            }
            return NULL;
        }
        if(root->val > key)
            root->left = deleteNode(root->left,key);
        if(root->val < key)
            root->right = deleteNode(root->right,key);
        return root;
    }
};
