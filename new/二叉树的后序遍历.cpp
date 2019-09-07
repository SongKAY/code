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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if(root==NULL)
            return result;
        s.push(root);
        while(!s.empty()){
            TreeNode *t = s.top();
            s.pop();
            result.insert(result.begin(),t->val);
            if(t->left!=NULL)
                s.push(t->left);
            if(t->right!=NULL)
                s.push(t->right);
        }
        return result;
    }
};
