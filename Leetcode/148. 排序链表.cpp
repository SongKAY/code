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
    void swap(ListNode *p,ListNode *q){
        int temp = p->val;
        p->val = q->val;
        q->val = temp;
    }
    void quickSort(ListNode *head,ListNode *tail){
        if(head==tail)
            return;
        ListNode *s = head;
        ListNode *cur = head;
        int pivol = head->val;
        while(cur!=NULL&&cur!=tail){
            if(cur->val<pivol){
                s = s->next;
                swap(cur,s);
            }
            cur = cur->next;
        }
        swap(s,head);
        quickSort(head,s);
        quickSort(s->next,tail);
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        quickSort(head,NULL);
        return head;

    }
};
