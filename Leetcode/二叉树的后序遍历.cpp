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
        if(root==NULL)
            return result;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode *temp = s.top();
            s.pop();
            result.insert(result.begin(),temp->val);
            if(temp->left)
                s.push(temp->left);
            if(temp->right)
                s.push(temp->right);
        }
        return result;
    }
};
