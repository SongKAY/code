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
    void swap(ListNode *a, ListNode* b){
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }
    ListNode* partition(ListNode *head,ListNode *tail){
        int pivol = head->val;
        ListNode *cur = head->next;
        ListNode *s = head;
        while(cur!=NULL&&cur!=tail){
            if(cur->val<pivol){
                s=s->next;
                swap(s,cur);
            }
            cur=cur->next;
        }
        swap(head,s);
        return s;
    }
    
    void quicksort(ListNode *head, ListNode* tail){
        if(head==tail||head->next==NULL){
            return;
        }
        ListNode *mid = partition(head,tail);
        quicksort(head,mid);
        quicksort(mid->next,tail);
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL)
            return head;
        quicksort(head,NULL);
        return head;
    }
};
