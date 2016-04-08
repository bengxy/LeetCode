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
        
    }
    ListNode* sort_sub_list(ListNode* head, ListNode* end){
    	if( head == NULL || head->next == NULL) return head;
        int base = head->val;
        ListNode* p = head->next;
        ListNode* last = head;
		ListNode* tmp_head;
		ListNode* p_next;
         {
        	if( p->val < base ){
        		//p_next = p->next;
        		last->next = p->next;
        		p->next = head;
        		head = p;
        		p = last->next;
        	}
        	else{
        		last = last->next;
        		p = p->next;
        	}
        }
    }
};