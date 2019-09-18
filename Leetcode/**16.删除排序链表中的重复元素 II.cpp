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
        ListNode *pre = new ListNode(-1);
        ListNode *dummy = pre;
        pre->next = head;
        ListNode *cur = head;
        while(cur!=NULL&&cur->next!=NULL){
            if(cur->val==cur->next->val){
                while(cur->next!=NULL&&cur->val==cur->next->val)
                    cur = cur->next;
                pre->next = cur->next;
                cur = cur->next;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
