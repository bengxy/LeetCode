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
        if( head == NULL || head->next == NULL)
            return head;
        //>=2
        ListNode* tail = head->next->next;
        while( tail!=NULL){
            tail = tail->next;
        }
        head = qs(head, tail);
        return head;
    }
    ListNode* qs(ListNode* head, ListNode* tail){
        //>=2
        if( head->next->next == tail){
            if(head->val > head->next->val){
                //ListNode* tmp = tail;
                head->next->next = head;
                head = head->next;
                head->next->next = tail;
            }
            return head;
        }
        ListNode* holder = head;
        ListNode* p = head;
        while(p->next!=tail){
            if(p->next->val < head->val){
                ListNode* tmp = p->next->next;
                p->next->next = holder;
                holder = p->next;
                p->next = tmp;
            }
            else{
                p=p->next;
            }
        }
        cout<<"iter"<<endl;
        ListNode* buf = holder;
        while(buf!=NULL){
            cout<<buf->val<<endl;
        }


        if( !(holder != head && holder->next != head) )
            holder = qs(holder, head);
        if( head->next!=tail && head->next->next!=tail)
            head->next = qs(head->next, tail);
        return holder;
    }
};