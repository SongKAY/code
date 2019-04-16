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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> result;
            if(pRoot==NULL)
                return result;
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty()){
                int size = q.size();
                vector<int> temp;
                for(int i=0;i<size;i++){
                    TreeNode *t = q.front();
                    q.pop();
                    temp.push_back(t->val);
                    if(t->left!=NULL)
                        q.push(t->left);
                    if(t->right!=NULL)
                        q.push(t->right);
                }
                result.push_back(temp);
            }
            return result;
        }
    
};
