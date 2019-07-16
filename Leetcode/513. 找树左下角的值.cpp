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
    int maxdepth(TreeNode *root){
        if(root==NULL)
            return 0;
        if(root->left==NULL&&root->right==NULL)
            return 1;
        int left = maxdepth(root->left);
        int right = maxdepth(root->right);
        return max(left,right) + 1;
    }
    
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return 0;
        int maxlen = maxdepth(root);
        queue<TreeNode*> q;
        vector<int> result;
        q.push(root);
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            cnt ++;
            for(int i=0;i<size;i++){
                TreeNode *t = q.front();
                q.pop();
                if(cnt==maxlen)
                    return t->val;
                result.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        }
        return 0;
    }
};
