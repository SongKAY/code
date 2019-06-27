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
    vector<vector<int>> result;
    void dfs(TreeNode* root,vector<int> temp,int sum,int t){
        if(root->left==NULL&&root->right==NULL){
            if(t==sum){
                result.push_back(temp);
            }
            return;
        }
        if(root->left!=NULL){
            temp.push_back(root->left->val);
            dfs(root->left,temp,sum+root->left->val,t);
            temp.pop_back();
        }
        if(root->right!=NULL){
            temp.push_back(root->right->val);
            dfs(root->right,temp,sum+root->right->val,t);
            temp.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return result;
        vector<int> temp;
        temp.push_back(root->val);
        dfs(root,temp,root->val,sum);
        return result;
    }
};
