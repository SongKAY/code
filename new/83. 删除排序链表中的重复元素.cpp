/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* pre = head;
        ListNode * cur = head->next;
        while(cur!=NULL){
            while(cur!=NULL&&pre->val==cur->val)
                cur = cur->next;
            pre->next = cur;
            pre = cur;
            if(cur!=NULL)
                cur = cur->next;
        }
        return head;
    }
};
