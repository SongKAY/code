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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL||pHead->next==NULL)
            return pHead;
        ListNode *pre = pHead;
        ListNode *cur = pHead->next;
        ListNode *temp = pHead->next->next;
        pHead->next = NULL;
        while(1){
            cur->next = pre;
            pre = cur;
            cur = temp;
            if(cur==NULL)
                break;
            temp = temp->next;
        }

        return pre;
    }
};
