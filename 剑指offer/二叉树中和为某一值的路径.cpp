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
    vector<vector<int>> result;
    void dfs(vector<int> temp,int number,TreeNode* root,int sum){
        if(sum==number){
            if(root->left==NULL&&root->right==NULL)
                result.push_back(temp);
            return;
        }
        if(sum>number){
            return;
        }
        if(root->left!=NULL){
            temp.push_back(root->left->val);
            dfs(temp,number,root->left,sum+root->left->val);
            temp.pop_back();
        }
        if(root->right!=NULL){
            temp.push_back(root->right->val);
            dfs(temp,number,root->right,sum+root->right->val);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==NULL)
            return result;
        else{
            vector<int> temp;
            temp.push_back(root->val);
            dfs(temp,expectNumber,root,root->val);
            return result;
        }
    }
};
