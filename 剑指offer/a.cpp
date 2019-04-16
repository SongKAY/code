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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode * temp1 = pHead1;
        int len1=0,len2=0;
        while(temp1!=NULL){
            len1 ++;
            temp1 = temp1->next;
        }
        ListNode *temp2 = pHead2;
        while(temp2!=NULL){
            len2 ++;
            temp2 = temp2->next;
        }
        int res = abs(len1-len2);
        if(len1>len2){
            temp1 = pHead1;
            while(res--)
                temp1 = temp1->next;
            while(temp1!=pHead2){
                temp1 = temp1->next;
                pHead2 = pHead2->next;
            }
            return temp1;
        }
        else{
            temp2 = pHead2;
            while(res--)
                temp2 = temp2->next;
            while(temp2!=pHead1){
                temp2 = temp2->next;
                pHead1 = pHead1->next;
            }
            return temp2;
        }
    }
};
