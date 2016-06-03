/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //0-6
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.empty()){
    		return NULL;
    	}
    	for(int skip=1;skip<lists.size();skip*=2){
    		for( int i=0;i+skip<lists.size();i+=skip*2){
    			lists[i] = merge(lists[i], lists[i+skip]);
    		}
    	}
    	return lists[0];
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
    	if(l1==NULL) return l2;
    	if(l2==NULL) return l1;
    	if( l1->val < l2->val){
    		l1->next = merge(l1->next, l2);
    		return l1;	
    	}
    	else{
    		l2->next = merge(l1, l2->next);
    		return l2;	
    	}
    }
};