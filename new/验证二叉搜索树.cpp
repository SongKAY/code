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
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        int flag = 0;
        int temp = -INT_MAX;
        stack<TreeNode*> s;
        while(root!=NULL||!s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            TreeNode *t = s.top();
            s.pop();
            if(!flag){
                temp = t->val;
                flag = 1;
                root = t->right;
            }
            else{
                if(t->val<=temp)
                    return false;
                temp = t->val;
                root = t->right;
            }
        }
        return true;
    }
};
