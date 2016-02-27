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
    ListNode* swapPairs(ListNode* head) {
    	//if( head == NULL) return head;
    	ListNode* base = head;
    	if( head== NULL || head->next == NULL )
    		return head;
    	ListNode* base = head;
    	head = head->next;
    	while( base!=NULL && base->next != NULL){
    		ListNode* last;
    		ListNode* second = base->next;
    		//ListNode* link = second->next;
    		base->next = second->next;
    		second->next = base;
    		base = base->next;
    	}
    	return head;
       // ListNode* tmp = head->next;
    }
};