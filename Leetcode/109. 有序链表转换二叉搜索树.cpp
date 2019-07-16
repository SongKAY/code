/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL){
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = head;
        while(fast!=NULL&&fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        while(pre->next!=slow)
            pre = pre->next;
        TreeNode *root = new TreeNode(slow->val);
        ListNode *newhead = slow->next;
        pre->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(newhead);
        return root;
    }
};

