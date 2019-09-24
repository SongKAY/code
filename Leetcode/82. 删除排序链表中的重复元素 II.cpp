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
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;
        pre->next = head;
        ListNode *cur = head;
        while(cur!=NULL&&cur->next!=NULL){
            if(cur->val!=cur->next->val){
                pre->next = cur;
                pre = cur;
                cur = cur->next;
            }
            else{
                while(cur!=NULL&&cur->next!=NULL&&cur->val==cur->next->val){
                    cur = cur->next;
                }
                cur = cur->next;
                pre->next = cur;
            }
        }
        return dummy->next;
    }
};
