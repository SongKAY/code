//注意是根据后序, 后序的根永远在最后
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
    TreeNode* dfs(vector<int>& pre, int s1,int e1, vector<int>& post,int s2,int e2){
        if(s1>e1&&s2>e2){
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[s1]);
        if(s1==e1&&s2==e2){
            return root;
        }
        int i = s2;
        for(;i<e2;i++){
            if(pre[s1+1]==post[i])
                break;
        }
        int cnt = i-s2+1;
        TreeNode *left = dfs(pre,s1+1,s1+cnt,post,s2,i);
        TreeNode *right = dfs(pre,s1+cnt+1,e1,post,i+1,e2-1);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        TreeNode*root = dfs(pre,0,n-1,post,0,n-1);
        return root;
    }
};
