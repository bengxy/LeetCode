class LRUCache{
private:
    typedef struct MemNode{
        int v;
        Node* next;
        Node* last;
    }Node;
    unordered_map<int, Node*> m;
    Node* head;
    //Node* tail;
public:
    LRUCache(int capacity) {
        //init
        head = new Node[capacity+1];
        for(int i=0;i<capacity;i++){
            h[i].next = h+i+1;
        }
        h[capacity].next = h;
        tail = h[capacity].next;



    }
    
    int get(int key) {
        auto pos = m.find(key);
        if( pos == m.end())
            return -1;
        else{
            
        }
    }
    
    void set(int key, int value) {
        
    }
};