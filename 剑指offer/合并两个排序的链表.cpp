/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
        else if(pHead2==NULL)
            return pHead1;
        else{
            ListNode *temp;
            if(pHead1->val<pHead2->val){
                temp = pHead1;
                pHead1 = pHead1->next;
                temp->next = Merge(pHead1,pHead2);
            }
            else{
                temp = pHead2;
                pHead2 = pHead2->next;
                temp->next = Merge(pHead1,pHead2);
            }
            return temp;
        }
    }
};
