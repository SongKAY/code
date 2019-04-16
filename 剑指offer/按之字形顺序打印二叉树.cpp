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
        int flag = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode *t = q.front();
                temp.push_back(t->val);
                q.pop();
                if(t->left!=NULL)
                    q.push(t->left);
                if(t->right!=NULL)
                    q.push(t->right);
            }
            if(flag)
                reverse(temp.begin(),temp.end());
            flag = 1-flag;
            result.push_back(temp);
        }
        return result;
    }
    
};
