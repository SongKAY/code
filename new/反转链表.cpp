//递归
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *temp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
};


//非递归
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *temp = head->next;
        while(temp!=NULL){
            cur->next = pre;
            pre = cur;
            cur = temp;
            temp = temp->next;
        }
        cur->next = pre;
        return cur;
    }
};
