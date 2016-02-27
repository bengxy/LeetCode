/*#include <iostream>
using namespace std;*/

class MinStack {
public:
    void push(int x) {
        Num* tmp = new Num;
        tmp->val = x;
        tmp->next = head.next;
        head.next = tmp;
    }

    void pop() {
    	if( head.next == NULL)
    		return ;
    	Num* tmp = head.next;
        head.next = tmp->next;

        delete( tmp );
    }

    int top() {
        return (head.next == NULL)? 0:head.next->val;
    }

    int getMin() {
        Num* tmp = head.next;
        if( head.next==NULL) return 0;
        int min = head.next->val;
        while( tmp!=NULL){
        	if( min > tmp->val)
        		min = tmp->val;
        	tmp = tmp->next;
        }
        return min;

    }

    class Num{
    public:
    	Num(){val = 0, next = NULL;}
    	int val;
    	Num* next;
    };
    Num head;
};
/*int main(void){
	MinStack x;
	x.push(2);
	cout<<x.top()<<endl;
	x.push(1);
	cout<<x.top()<<endl;
	x.push(3);
	cout<<x.getMin()<<endl;
	x.pop();
	cout<<x.top()<<endl;
	return 0;
}*/