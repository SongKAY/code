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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)
            return false;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *t = q.front();
                q.pop();
                if(t->left==NULL){
                    if(t->right!=NULL)
                        return false;
                    flag = 1;
                }
                else{
                    if(flag)
                        return false;
                    q.push(t->left);
                    if(t->right==NULL)
                        flag = 1;
                    else
                        q.push(t->right);
                }
            }
        }
        return true;
    }
};
