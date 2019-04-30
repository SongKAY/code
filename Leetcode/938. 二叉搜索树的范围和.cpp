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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while(!q.empty()){
            TreeNode *t = q.front();
            q.pop();
            if(t->left!=NULL)
                q.push(t->left);
            if(t->right!=NULL)
                q.push(t->right);
            v.push_back(t->val);
        }
        int sum = 0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(v[i]<L)
                continue;
            if(v[i]>R)
                break;
            sum += v[i];
        }
        return sum;
    }
};
