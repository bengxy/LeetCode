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
        if( head == NULL || head->next == NULL){
        	return head;
        }
        ListNode* first = head;
        ListNode* second = first->next;
        ListNode* rest = second->next;
        head = second;
        ListNode* lastone = first;
        
        bool flag = false;
        while( first!=NULL){
        	second->next = first;
        	first->next = rest;
        	first = rest;
        
        if( flag ){
            lastone->next = second;
            
            lastone = second->next;
        }
        	
        flag = true;
        	if( first != NULL && first->next!=NULL){
        	    	second = first->next;
        			rest = second->next;
        	}
        	else{
        		lastone->next = first; //bu qi lai
        		break;
        	}
        }
        
        return head;
    }
};