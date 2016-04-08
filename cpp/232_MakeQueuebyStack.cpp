class Queue {
public:
    stack<int> base;
    stack<int> mirror;
    // Push element x to the back of queue.
    void push(int x) {
        base.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if( mirror.empty() ){
            while( !base.empty() ){
                mirror.push( base.top() );
                base.pop();
            }
        }
        if( !mirror.empty() ) mirror.pop();
    }

    // Get the front element.
    int peek(void) {
        if( mirror.empty() ){
            while( !base.empty() ){
                mirror.push( base.top() );
                base.pop();
            }
        }
        if( !mirror.empty() ) return mirror.top();
        else return 0;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return base.empty() && mirror.empty();
    }
};