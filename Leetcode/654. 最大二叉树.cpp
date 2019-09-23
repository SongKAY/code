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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums.begin(), nums.end());
    }
    TreeNode *construct(vector<int>::iterator l,vector<int>::iterator r){
        if(l==r)
            return NULL;
        auto it = max_element(l,r);
        TreeNode* temp = new TreeNode(*it);
        temp->left = construct(l,it);
        temp->right = construct(it+1,r);
        return temp;
    }
};

