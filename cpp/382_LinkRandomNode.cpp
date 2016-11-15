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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
	ListNode* _head;
    Solution(ListNode* head) {
        _head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
    	if(_head == NULL)
    		return 0;
    	int res = _head->val;
    	int cnt = 1;
        ListNode* ptr = _head->next;;
        while(ptr !=NULL){
        	cnt++;
        	if( rand()%cnt == 0){
        		res = ptr->val;
        	}
        	ptr = ptr->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */