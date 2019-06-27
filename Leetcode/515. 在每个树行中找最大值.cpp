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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> s;
        if(root==NULL)
            return result;
        s.push(root);
        while(!s.empty()){
            int size = s.size();
            int maxx = s.front()->val;
            while(size--){
                TreeNode* t = s.front();
                s.pop();
                maxx = max(maxx,t->val);
                if(t->right!=NULL)
                    s.push(t->right);
                if(t->left!=NULL)
                    s.push(t->left);
            }
            result.push_back(maxx);
        }
        return result;
    }
};
