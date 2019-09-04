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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        int n = lists.size();
        if(n<2)
            return lists[0];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<n;i++){
            if(lists[i]==NULL)
                continue;
            q.push(make_pair(lists[i]->val,i));
        }
        ListNode *head = new ListNode(-1);
        ListNode *p = head;
        while(!q.empty()){
            int t = q.top().first;
            int idx = q.top().second;
            q.pop();
            head->next = new ListNode(t);
            lists[idx] = lists[idx]->next;
            if(lists[idx]!=NULL){
                q.push(make_pair(lists[idx]->val,idx));
            }
            head = head->next;
        }
        return p->next;
    }
};
