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
    int sum = 0;
    void sum_left(TreeNode* node,int flag){
        if(node->left==NULL&&node->right==NULL){
            if(flag){
                sum += node->val;
            }
            return;
        }
        if(node->left!=NULL){
            sum_left(node->left,1);
        }
        if(node->right!=NULL){
            sum_left(node->right,0);
        }
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left!=NULL)
            sum_left(root->left,1);
        if(root->right!=NULL)
            sum_left(root->right,0);
        return sum;
    }
};
