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
    ListNode* deleteDuplicates(ListNode* head) {
    	if(head == NULL || head->next == NULL)
    		return head;
    	ListNode* x = new ListNode(0);
    	
        x->next = head;
        ListNode* nh = head;
        ListNode* last = x;
        bool mark = false;
        while(nh->next != NULL){
        	int a = nh->next->val;
        	int b = nh->val;
        	if( a == b || mark ){
        		mark = (a==b);
        		last->next = nh->next;
        		delete(nh);
        		nh = last->next;
        	}
        	// else if(mark){
        	// 	mark = false;
        	// 	last->next = nh->next;
        	// 	delete(nh);
        	// 	nh = last->next;
        	// }
        	else{
        		nh = nh->next;
        		last = last->next;
        	}
        }
        if( mark ){
        	last->next = nh->next;
        	delete(nh);
        }
        head = x->next;
        delete(x);
        return head;
    }
};