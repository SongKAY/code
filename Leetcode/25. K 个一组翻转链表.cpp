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
    ListNode *reverse(ListNode *head){
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    ListNode *reverseK(ListNode *head,int k){
        int cnt = 0;
        ListNode *temp = head;
        while(temp!=NULL){
            cnt ++;
            if(cnt==k)
                break;
            temp = temp->next;
        }
        if(cnt!=k)
            return head;
        else{
            ListNode *p = temp->next;
            temp->next = NULL;
            ListNode *n = reverseK(p,k);
            ListNode *result = reverse(head);
            head->next = n;
            return result;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //head = reverse(head);
        head = reverseK(head,k);
        //head = reverse(head);
        return head;
    }
};
