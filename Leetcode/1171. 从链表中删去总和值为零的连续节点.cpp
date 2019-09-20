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
        unordered_map<int,ListNode*> m;
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        dummy->next = head;
        m[0] = p;
        int cur = 0;
        int tempcur = 0;
        while(p=p->next){
            cur += p->val;
            if(m.find(cur)!=m.end()){
                ListNode* temp = m[cur]->next;
                m[cur]->next = p->next;
                tempcur = cur;
                while(temp!=p){
                    tempcur += temp->val;
                    m.erase(tempcur);
                    temp = temp->next;
                }
            }
            else
                m[cur] = p;
        }
        return dummy->next;
    }
};


