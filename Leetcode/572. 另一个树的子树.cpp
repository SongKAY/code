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
    bool check(TreeNode* s, TreeNode* t){
        if(s==NULL&&t==NULL)
            return true;
        if(s==NULL&&t!=NULL)
            return false;
        if(s!=NULL&&t==NULL)
            return false;
        if(s->val!=t->val)
            return false;
        if(s->val==t->val)
            return check(s->left,t->left) && check(s->right,t->right);
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool result = false;
        result = check(s,t);
        if(!result)
            if(s!=NULL)
                result = isSubtree(s->left,t);
        if(!result)
            if(s!=NULL)
                result = isSubtree(s->right,t);
        return result;
    }
};
