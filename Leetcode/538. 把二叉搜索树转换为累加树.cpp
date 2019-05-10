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
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return root;
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            TreeNode *t = q.front();
            q.pop();
            v.push_back(t->val);
            if(t->left!=NULL)
                q.push(t->left);
            if(t->right!=NULL)
                q.push(t->right);
        }
        vector<int> sum(v.size(),0);
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                if(i==j||v[i]>v[j])
                    continue;
                sum[i] += v[j];
            }
        }
        vector<TreeNode*> tree;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            tree.push_back(temp);
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
        for(int i=0;i<tree.size();i++){
            tree[i]->val += sum[i];
        }
        return root;
    }
};
