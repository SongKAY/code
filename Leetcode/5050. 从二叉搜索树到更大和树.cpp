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
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)
            return root;
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            TreeNode *t = q.front();
            v.push_back(t->val);
            q.pop();
            if(t->left!=NULL)
                q.push(t->left);
            if(t->right!=NULL)
                q.push(t->right);
        }
        vector<int> temp(v.size(),0);
        for(int i=0;i<v.size();i++){
            int sum = v[i];
            for(int j=0;j<v.size();j++){
                if(j!=i&&v[j]>=v[i])
                    sum += v[j];
            }
            temp[i]=sum;
        }
        q.push(root);
        int cnt = 0;
        while(!q.empty()){
            TreeNode *t = q.front();
            t->val = temp[cnt];
            cnt ++;
            q.pop();
            if(t->left!=NULL)
                q.push(t->left);
            if(t->right!=NULL)
                q.push(t->right);
        }
        return root;
    }
};
