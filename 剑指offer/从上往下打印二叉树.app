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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        if(root==NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *t = q.front();
            q.pop();
            result.push_back(t->val);
            if(t->left!=NULL)
                q.push(t->left);
            if(t->right!=NULL)
                q.push(t->right);
        }
        return result;
    }
};
