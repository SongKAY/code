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
    TreeNode*  construct(vector<int>& preorder, int l1,int r1, vector<int>& inorder,int l2,int r2){
        if(l1>r1&&l2>r2)
            return NULL;
        if(l1==r1){
            TreeNode* root = new TreeNode(preorder[l1]);
            return root;
        }
        TreeNode *root = new TreeNode(preorder[l1]);
        int cnt = l2;
        int k = 0;
        while(cnt<=r2&&inorder[cnt]!=preorder[l1]){
            cnt ++;
            k++;
        }
        root->left = construct(preorder,l1+1,l1+k,inorder,l2,cnt-1);
        root->right = construct(preorder,l1+k+1,r1,inorder,cnt+1,r2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()||inorder.empty())
            return NULL;
        int n = preorder.size();
        TreeNode *root = construct(preorder,0,n-1,inorder,0,n-1);
        return root;
    }
};
