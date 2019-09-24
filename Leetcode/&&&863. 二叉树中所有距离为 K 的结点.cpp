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
    vector<int> result;
    unordered_map<int,TreeNode*> father;
    void construct(TreeNode* root){
        if(root==NULL)
            return;
        if(root->left){
            father[root->left->val] = root;
            construct(root->left);
        }
        if(root->right){
            father[root->right->val] = root;
            construct(root->right);
        }
    }
    void getans(int t,int K,TreeNode* root,vector<int>&visit){
        if(t==K){
            result.push_back(root->val);
            return;
        }
        if(root->left!=NULL&&!visit[root->left->val]){
            visit[root->left->val] = 1;
            getans(t+1,K,root->left,visit);
        }
        if(root->right!=NULL&&!visit[root->right->val]){
            visit[root->right->val] = 1;
            getans(t+1,K,root->right,visit);
        }
        if(father[root->val]!=NULL&&!visit[father[root->val]->val]){
            visit[father[root->val]->val] = 1;
            getans(t+1,K,father[root->val],visit);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> visit(501,0);
        construct(root);
        visit[target->val]=1;
        getans(0,K,target,visit);
        return result;
    }
};
