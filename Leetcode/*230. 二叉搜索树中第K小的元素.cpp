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
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<int> result;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            result.push_back(temp->val);
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
        sort(result.begin(),result.end());
        return result[k-1];
    }
};
