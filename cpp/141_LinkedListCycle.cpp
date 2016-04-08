//有更好的思路
//在有圈的图上追逐，快指针跳2格，慢指针1格
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> passed;
        ListNode* tmp = head;
        //bool cycle = true;
        while( tmp!= NULL){
        	if( passed.find(tmp)!= -1)
        		return false;
        	passed.insert(tmp);
        	tmp = tmp->next;
        }
        return true;
    }
};
