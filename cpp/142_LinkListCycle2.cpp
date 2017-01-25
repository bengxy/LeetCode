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
    ListNode *detectCycle(ListNode *head) {
    	//if(!head) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        bool meet = false;
        // int step = 0;
        // int cycle = 0;
        while(fast!=NULL && fast->next!=NULL){
        	fast = fast->next->next;
        	slow = slow->next;
        	//step++;
        	if(fast == slow){
        		//meet
        		meet = true;
        		break;
        	}
        }
        if(!meet)
        	return NULL;
        ListNode* p = head;
        ListNode* q = head;
       	while( slow->next!=fast ){
       		slow = slow->next;
       		p = p->next;
       	}
       	p = p->next;
       	while( p!=q){
       		p = p->next;
       		q = q->next;
       	}
       	return q;

    }
};