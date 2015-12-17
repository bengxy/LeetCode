/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	unordered_map<int, UndirectedGraphNode*> done;
	typedef pair<int, UndirectedGraphNode*> ele;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        UndirectedGraphNode* res = new UndirectedGraphNode();
        res->label = node->label;

        done.insert( ele(res->label, res));

        for(auto iter = node->neighbors.begin(); iter!=neighbors.end(); iter++){
        	if( !done.find(*iter->label) ）{
        		//not in hash
        		UndirectedGraphNode* tmp = cloneGraph(*iter);
        	}
        	else{
        		//in hash so skip; just add into the neighbors
        		res->neighbors.push_back( done.at(*iter->label) );
        	}
        }

        return res;
    }
};