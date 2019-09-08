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
        ListNode *temp = new ListNode(-1);
        temp->next = head;
        ListNode *pre = temp;
        ListNode *cur = head;
        while(cur!=NULL&&cur->next!=NULL){
            if(cur->val==cur->next->val){
                while(cur->next!=NULL&&cur->val==cur->next->val)
                    cur = cur->next;
                temp->next = cur->next;
                cur = cur->next;
            }
            else{
                temp = cur;
                cur = cur->next;
            }
        }
        return pre->next;
    }
};
