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
        stack<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.top();
            q.pop();
            result.push_back(temp->val);
            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
        }
        return result;
    }
};
