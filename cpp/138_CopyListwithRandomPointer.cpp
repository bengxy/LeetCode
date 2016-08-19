/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {    	
    	if(head == NULL)
        	return NULL;
        unordered_map<RandomListNode*, vector<RandomListNode*>> old2new;
        //RandomListNode new_head(head->label);
        RandomListNode* new_head = new RandomListNode(head->label);
        if(head->random){
        	if(old2new.find(head->random) != old2new.end())
        		old2new[head->random].push_back(new_head);
        	else{
        		vector<RandomListNode*> tmp;
        		tmp.push_back(new_head);
        		old2new[head->random] = tmp;
        	}
        }
        	

        RandomListNode* iter = head->next;
        RandomListNode* p;// = &new_head;
        RandomListNode* last = new_head;
        while(iter!=NULL){
        	//iter = 
        	p = new RandomListNode(iter->label);
        	if(iter->random){
        		if(old2new.find(iter->random) != old2new.end())
        			old2new[iter->random].push_back(p);
        		else{
        			vector<RandomListNode*> tmp;
        			tmp.push_back(p);
        			old2new[iter->random] = tmp;
        		}
        	}

        	last->next = p;

        	last = last->next;
        	iter = iter->next;
        }

        iter = head;
        p = new_head;
        while(iter!=NULL){
        	for( auto i:old2new[iter]){
        		i->random = p;
        	}
        	iter = iter->next;
        	p = p->next;
        }
        return new_head;
    }
};