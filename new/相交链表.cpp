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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0;
        ListNode* prea = headA;
        while(prea!=NULL){
            a++;
            prea = prea->next;
        }
        int b = 0;
        ListNode* preb = headB;
        while(preb!=NULL){
            b++;
            preb = preb->next;
        }
        int left = 0;
        if(a>b){
            left = a - b;
            while(left--)
                headA = headA->next;
            while(headA!=NULL&&headB!=NULL){
                if(headA==headB)
                    return headA;
                else{
                    headA = headA->next;
                    headB = headB->next;
                }
            }
            return NULL;
        }
        else{
            left = b - a;
            while(left--)
                headB = headB->next;
            while(headA!=NULL&&headB!=NULL){
                if(headA==headB)
                    return headA;
                else{
                    headA = headA->next;
                    headB = headB->next;
                }
            }
            return NULL;
        }
    }
};
