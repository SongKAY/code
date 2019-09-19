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
    void dfs(TreeNode *root,int temp, int sum){
        if(root==NULL)
            return;
        else{
            temp += root->val;
            if(temp==sum)
                result += 1;
            dfs(root->left,temp,sum);
            dfs(root->right,temp,sum);
        }
    }
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return 0;
        dfs(root,0,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return result;
    }
};
