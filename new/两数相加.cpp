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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *p = head;
        int sum = 0;
        while(l1!=NULL||l2!=NULL){
            int s = sum;
            if(l1!=NULL){
                s += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                s += l2->val;
                l2 = l2->next;
            }
            sum = s / 10;
            s = s % 10;
            head->next = new ListNode(s);
            head = head->next;
        }
        if(sum)
            head->next = new ListNode(sum);
        return p->next;
    }
};
