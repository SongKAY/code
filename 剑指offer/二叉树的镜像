/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL||(pRoot->left==NULL&&pRoot->right==NULL))
            return;
        else{
            if(pRoot->left!=NULL)
                Mirror(pRoot->left);
            if(pRoot->right!=NULL)
                Mirror(pRoot->right);
            TreeNode *temp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = temp;
        }
        return;
    }
};
