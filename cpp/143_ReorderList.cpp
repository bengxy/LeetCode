
 // struct ListNode {
 //     int val;
 //     ListNode *next;
 //     ListNode(int x) : val(x), next(NULL) {}
 // };
 
class Solution {
public:
    void reorderList(ListNode* head) {
    	ListNode* ptr = head;
    	int count = 0;
    	//total Nodes
        while( ptr!= NULL){
        	ptr = ptr->next;
        	count++;
        }
        //cout<<count<<endl;
        if( count<3)
        	return ;
        count = count/2;
        //cout<<" divide "<< count <<endl;
        ptr = head;
        while( count-->0 ){
        	ptr = ptr->next;
        }
        //cout<<"ptr->val "<<ptr->val<<endl;
        ListNode* runner = ptr->next;
        ListNode* tmp;
        while( runner->next!=NULL){
        	tmp = ptr->next;
        	ptr->next = runner->next;
        	runner->next = runner->next->next;
        	ptr->next->next = tmp;
        }
        //cout<<"reverse success"<<endl;
        ListNode* lh = head;
		ListNode* rh = ptr->next;
		//cout<< "rh "<<rh->val<<endl;

		ptr->next = NULL;
        while(rh != NULL){
        	//ListNode* tmpl = lh->next;
        	ListNode* tmpr = rh->next;
        	rh->next = lh->next;
        	lh->next = rh;
        	lh = rh->next;
        	rh = tmpr;
        }
        return ;
    }
};
