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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        for(int i=0;i<n;i++){
            if(fast==NULL)
                break;
            fast = fast->next;
        }
        if(fast==NULL)
            return head->next;
        ListNode *slow = head;
        ListNode *pre = head;
        while(fast!=NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        pre->next = slow->next;
        return head;
    }
};
