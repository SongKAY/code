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
    vector<TreeNode*> generate(int l,int r){
        vector<TreeNode*> ans;
        if(l>r){
            ans.push_back(NULL);
            return ans;
        }
        for(int i=l;i<=r;i++){
            vector<TreeNode*> left = generate(l,i-1);
            vector<TreeNode*> right = generate(i+1,r);
            for(auto lnode:left){
                for(auto rnode:right){
                    TreeNode *root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    ans.push_back(root);
                }
            }
        } 
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n)
            return generate(1,n);
        else
            return vector<TreeNode*>{};
    }
};
