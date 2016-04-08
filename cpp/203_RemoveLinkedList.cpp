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
    ListNode* removeElements(ListNode* head, int val) {
    	if( head == NULL) return NULL;
    	ListNode* last = head;
        while(last->next!=NULL){
        	if( last->next->val == val){
        		last->next = last->next->next;
        	}
        	else{
        		last = last->next;
        	}

        }
        if( head->val == val)
        	head = head->next;
        return head;
    }
};