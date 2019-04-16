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
    bool isSymmetrical(TreeNode* l, TreeNode* r){
        if(l==NULL&&r==NULL)
            return true;
        if(l==NULL&&r!=NULL)
            return false;
        if(r==NULL&&l!=NULL)
            return false;
        if(l->val!=r->val)
            return false;
        return isSymmetrical(l->left,r->right) && isSymmetrical(r->left,l->right);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return true;
        return isSymmetrical(pRoot->left,pRoot->right);
    }
};
