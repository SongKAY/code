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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL)
            return result;
        stack<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t = q.top();
            q.pop();
            result.push_back(t->val);
            if(t->right!=NULL)
                q.push(t->right);
            if(t->left!=NULL)
                q.push(t->left);
        }
        return result;
    }
};
