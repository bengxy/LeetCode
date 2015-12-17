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
    ListNode* sortList(ListNode* head) {
        psort(&head);
        return head;
    }
    void psort(ListNode** headPos, ListNode** tailPos == NULL){
    	ListNode* head = *headPos;
    	if( head == NULL)
    		return ;
    	if( head->next == NULL ){
    		tailPos = &head;
    		return ;
    	}
    	
    	int base = head->val;
    	
    	ListNode* iter;
    	//ListNode* lh = head;
    	ListNode* lt = head;

    	ListNode* last = head;
    	ListNode* tmp;
    	while( iter != NULL){
    		if( iter->val < base){
    			last->next = iter->next;
    			iter->next = lt->next;
    			lt->next = iter;
    			lt = iter;
    			//iter = last->next;
    		}
    		else{
    			last = iter;
    			//iter = iter->next;
    		}
    		iter = last->next;
    	}
    	ListNode* lh = head->next;
    	ListNode* rh = lt->next;
    	psort(&lh, &lt);
    	psort(&rh, &last);
    	lt->next = head;
    	head->next = rh;
    	*headPos = head;
    	*tailPos = last;
    }
};