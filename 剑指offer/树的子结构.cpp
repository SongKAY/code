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
    bool check(TreeNode* p1, TreeNode* p2){
        if(p2==NULL)
            return true;
        if(p1==NULL)
            return false;
        if(p1->val!=p2->val)
            return false;
        return check(p1->left,p2->left) && check(p1->right,p2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {    
        bool result = false;
        if(pRoot1!=NULL&&pRoot2!=NULL){
            if(pRoot1->val == pRoot2->val)
                result = check(pRoot1,pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->left,pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->right,pRoot2);
        }
        return result;
    }
};
