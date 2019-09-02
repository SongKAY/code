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
        bool flag = true;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *cur = q.front();
                q.pop();
                if(cur->left!=NULL){
                    if(!flag)
                        return false;
                    q.push(cur->left);
                    if(cur->right==NULL){
                        flag = false;
                    }
                    else
                        q.push(cur->right);
                }
                else{
                    if(cur->right!=NULL)
                        return false;
                    flag = false;
                }
            }
        }
        return true;
    }
};
