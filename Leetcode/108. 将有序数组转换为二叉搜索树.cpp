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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return NULL;
        return construct(nums,0,nums.size()-1);
    }
    TreeNode *construct(vector<int>&nums,int l,int r){
        if(l>r)
            return NULL;
        int mid = (l+r)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = construct(nums,l,mid-1);
        root->right = construct(nums,mid+1,r);
        return root;
    }
};
