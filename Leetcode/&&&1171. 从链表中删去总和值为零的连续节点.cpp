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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head==NULL)
            return NULL;
        map<int,ListNode*> m;
        ListNode* cur = head;
        ListNode* pre = new ListNode(0);
        ListNode* result = pre;
        pre->next = head;
        int sum = 0;
        m[0] = pre;
        while(cur!=NULL){
            sum += cur->val;
            if(m.find(sum)!=m.end()){
                ListNode *temp = m[sum]->next;
                m[sum]->next = cur->next;
                int val = sum;
                while(temp!=cur){
                    val += temp->val;
                    m.erase(val);
                    temp=temp->next;
                }
            }
            else{
                m[sum] = cur;
            }
            cur = cur->next;
        }
        return result->next;
    }
};
