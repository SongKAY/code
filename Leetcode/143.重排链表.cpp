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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return;
        ListNode *p1 = head;
        ListNode *p2 = head;
        while(p2->next!=NULL&&p2->next->next!=NULL){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = p1->next;
        p1->next = NULL;
        p1 = head;
        
        ListNode *pre = NULL;
        ListNode *cur = p2;
        ListNode *temp = p2->next;
        while(temp!=NULL){
            cur->next=pre;
            pre=cur;
            cur=temp;
            temp=temp->next;
        }
        cur->next=pre;
        p2 = cur;
        while(p2!=NULL){
            ListNode *next1 = p1->next;
            ListNode *next2 = p2->next;
            p1->next = p2;
            p2->next = next1;
            p1 = next1;
            p2 = next2;
        }
        return;
    }
};
