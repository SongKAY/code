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
    bool isSymmetric(TreeNode* l1,TreeNode* l2){
        if(l1==NULL&&l2==NULL)
            return true;
        if((l1==NULL&&l2!=NULL)||(l2==NULL&&l1!=NULL))
            return false;
        if(l1!=NULL&&l2!=NULL){
            if(l1->val!=l2->val)
                return false;
            else{
                return isSymmetric(l1->left,l2->right) && isSymmetric(l1->right,l2->left);
            }
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isSymmetric(root->left,root->right);
    }
};
