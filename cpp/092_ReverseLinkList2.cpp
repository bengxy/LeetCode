class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        int i=0;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *p=dummy;
        
        while(++i<m && p->next){
            p=p->next;
        }
        ListNode *tail=p->next;
        head=p;
        p=p->next;
        
        ListNode *r=p, *cur=p->next, *t;
        
        while(i++<n && cur){
            t=cur->next;
            cur->next=r;
            r=cur;
            cur=t;
            
            p=p->next;
        }
    
        head->next=r;
        tail->next=t;
        return dummy->next;
    }
};