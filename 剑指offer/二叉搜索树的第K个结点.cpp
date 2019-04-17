/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:

    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL||k<=0)
            return NULL;
        vector<TreeNode*> result;
        Inorder(pRoot,result);
        if(k>result.size())
            return NULL;
        return result[k-1];
    }
    void Inorder(TreeNode *pRoot,vector<TreeNode*> &result){
        if(pRoot==NULL)
            return;
        Inorder(pRoot->left,result);
        result.push_back(pRoot);
        Inorder(pRoot->right,result);
    }
};
