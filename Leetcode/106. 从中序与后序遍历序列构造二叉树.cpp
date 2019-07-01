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
    TreeNode* dfs(vector<int> inorder,int s1,int e1,vector<int> postorder,int s2,int e2){
        if(s1>e1&&s2>e2)
            return NULL;
        if(s1==e1&&s2==e2){
            TreeNode *root = new TreeNode(postorder[e2]);
            return root;
        }
        TreeNode *root = new TreeNode(postorder[e2]);
        int j = s1;
        while(j<=e1&&inorder[j]!=postorder[e2])
            j++;
        int cnt = j - s1 - 1;
        // cout<<s1<<' '<<j-1<<' '<<s2<<' '<<s2+cnt<<endl;
        // cout<<j+1<<" "<<e1<<' '<<s2+cnt+1<<' '<<e2-1<<endl;
        root->left = dfs(inorder,s1,j-1,postorder,s2,s2+cnt);
        root->right = dfs(inorder,j+1,e1,postorder,s2+cnt+1,e2-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())
            return NULL;
        int n = inorder.size();
        TreeNode *root = dfs(inorder,0,n-1,postorder,0,n-1);
        return root;
    }
};
