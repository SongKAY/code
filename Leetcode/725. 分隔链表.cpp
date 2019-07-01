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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int l = 0;
        ListNode *temp = root;
        while(temp!=NULL){
            l ++;
            temp = temp->next;
        }
        vector<ListNode*> result;
        if(l<=k){
            for(int i=0;i<l;i++){
                result.push_back(new ListNode(root->val));
                root = root->next;
            }
            for(int i=l;i<k;i++){
                ListNode *temp = NULL;
                result.push_back(temp);
            }
            return result;
        }        
        else{
            int cnt = l / k; //每个里面放多少
            int left = l % k; //前left放cnt+1
            for(int i=0;i<k;i++){
                ListNode *temp = new ListNode(root->val);
                result.push_back(temp);
                for(int i=0;i<cnt-1;i++){
                    root = root->next;
                    temp->next = new ListNode(root->val);
                    temp = temp->next;
                }
                if(left){
                    left -= 1;
                    root = root->next;
                    temp->next = new ListNode(root->val);
                    temp = temp->next;
                }
                root = root->next;
            }
            return result;
        }
        return result;
    }
};
