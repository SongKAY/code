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
    void swap(ListNode *a,ListNode *b){
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }
    void quicksort(ListNode *head,ListNode *tail){
        if(head==tail)
            return;
        ListNode *cur = head;
        ListNode *s = head;
        int k = head->val;
        while(cur!=NULL&&cur!=tail){
            if(cur->val<k){
                s = s->next;
                swap(s,cur);
            }
            cur = cur->next;
        }
        swap(head,s);
        quicksort(head,s);
        quicksort(s->next,tail);
    }
    
    ListNode* sortList(ListNode* head) {
        quicksort(head,NULL);
        return head;
    }
};
