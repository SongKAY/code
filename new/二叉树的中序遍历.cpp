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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> q;
        TreeNode *t = root;
        while(t||!q.empty()){
            while(t){
                q.push(t);
                t=t->left;
            }
            t = q.top();
            q.pop();
            result.push_back(t->val);
            t=t->right;
        }
        return result;
    }
};
