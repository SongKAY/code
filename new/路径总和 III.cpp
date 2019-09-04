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
    int result = 0;
    void dfs(TreeNode *root,int sum,int temp){
        if(root==NULL)
            return;
        temp += root->val;
        if(temp==sum)
            result += 1;
        dfs(root->left,sum,temp);
        dfs(root->right,sum,temp);
    }
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return 0;
        dfs(root,sum,0);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return result;
    }
};
