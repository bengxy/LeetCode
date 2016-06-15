class LRUCache{
public:
    LRUCache(int capacity) {
	    
	    typedef struct node{
	    	LRUNode* last;
	    	LRUNode* next;
	    	int val;
	    }LRUNode;

	    LRUNode* head;
		unordered_map<int, LRUNode*> cache;
    }

    int get(int key) {
        
    }
    
    void set(int key, int value) {
        if ( cache.find(key)==cache.end()){
        	LRUNode tmp = new LRUNode();
        	tmp->val = value;
        	tmp->last = head->last;
        	tmp->next = head;
        	cache[key] = &tmp;
        }
    }
    void move2head(LRUNode* target){

    }
    void insert2head(LRUNode* target){

    }
};