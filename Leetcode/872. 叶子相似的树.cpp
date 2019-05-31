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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL||root2==NULL)
            return false;
        stack<TreeNode*> q1;
        stack<TreeNode*> q2;
        vector<int> v1;
        vector<int> v2;
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty()){
            TreeNode* temp = q1.top();
            q1.pop();
            if(temp->left==NULL&&temp->right==NULL)
                v1.push_back(temp->val);
            else{
                if(temp->left!=NULL)
                    q1.push(temp->left);
                if(temp->right!=NULL)
                    q1.push(temp->right);
            }
        }
        while(!q2.empty()){
            TreeNode* temp = q2.top();
            q2.pop();
            if(temp->left==NULL&&temp->right==NULL)
                v2.push_back(temp->val);
            else{
                if(temp->left!=NULL)
                    q2.push(temp->left);
                if(temp->right!=NULL)
                    q2.push(temp->right);
            }
        }
        if(v1.size()!=v2.size())
            return false;
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i])
                return false;
        }
        return true;
    }
};
