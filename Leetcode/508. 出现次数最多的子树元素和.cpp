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
    map<int,int> m;
    int result = 0;
    int getSum(TreeNode* root){
        if(root==NULL)
            return 0;
        int sum = root->val;
        sum += getSum(root->left);
        sum += getSum(root->right);
        m[sum] ++;
        result = max(m[sum],result);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int temp = getSum(root);
        vector<int> t;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second==result){
                t.push_back(it->first);
            }
        }
        return t;
    }
};
