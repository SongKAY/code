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
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode *> q;
        int cnt = 0;
        q.push(root);
        while(!q.empty()){
            cnt += q.size();
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
        }
        return cnt;
    }
};
