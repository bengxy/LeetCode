/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //做法: 遍历总长，让长的一个先走len(more-less)  2*(N+M)+MAX(N,M) O(N+M)
 //做法2 TODO more quick :  2*(N+M)  O(N+M)
 /* 让A B一起走，A或B走到头之后，均跳到另一个串上，当两个串都换到另一个串后，开始判断是否相等
 /* 原理 partA + intersec + partB  =  partB + intersec + partA
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if(!headA || !headB)
    		return NULL;
        int na=0;
        int nb=0;
        ListNode* pa = headA;
        ListNode* pb = headB;
        while( pa->next ){
        	pa = pa->next;
        	na++;
        }
        while( pb->next ){
        	pb = pb->next;
        	nb++;
        }
        ListNode* more;
        ListNode* less;
        int step;
        if(na>nb){
        	more = headA;
        	less = headB;
        	step = na-nb;
        }
        else{
        	more = headB;
        	less = headA;
        	step = nb-na;
        }
        for(int i=0;i<step;i++){
        	more=more->next;
        }
        while( more!=less){
        	more = more->next;
        	less = less->next;
        	if(!more)
        		return NULL;
        }
        return more;
    }
};