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
        else if(lists.size()<2)
            return lists[0];
        priority_queue <pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        int n = lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]==NULL)
                continue;
            q.push(make_pair(lists[i]->val,i));
        }
        ListNode *head = new ListNode(-1);
        ListNode *temp = head;
        while(!q.empty()){
            pair<int,int> t = q.top();
            q.pop();
            temp->next = new ListNode(t.first);
            temp = temp->next;
            lists[t.second] = lists[t.second] ->next;
            if(lists[t.second]==NULL)
                continue;
            else{
                q.push(make_pair(lists[t.second]->val,t.second));
            }
        }
        return head->next;
    }
};
