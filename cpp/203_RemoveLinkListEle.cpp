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
        ListNode* x = new ListNode(0);
        x->next = head;
        ListNode* nh = x;
        while(nh->next!=NULL){
        	if(nh->next->val == val){
        		ListNode* tmp = nh->next;
        		nh->next = nh->next->next;
        		delete(tmp);
        	}
        	else{
        		nh = nh->next;
        	}
        }
        nh = x->next;
        delete(x);
        
        return nh;
    }
};