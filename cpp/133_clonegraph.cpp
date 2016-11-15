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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> passed;
        return builder(passed, node);
    }
    UndirectedGraphNode* builder(unordered_map<int, UndirectedGraphNode*>& passed,
        UndirectedGraphNode *node){
        if(node == NULL)
            return NULL;
        
        UndirectedGraphNode* mynode = new UndirectedGraphNode(node->label);
        passed[node->label] = mynode;

        for(auto& neighbors: node->neighbors){
        //for(int i=0;i<node->neighbors.size();i++){
          //  auto neighbors = node->neighbors[i];
            if( passed.find(neighbors->label) == passed.end()){
                UndirectedGraphNode* tmp = builder(passed, neighbors);
                mynode->neighbors.push_back(tmp);
            }
            else{
                mynode->neighbors.push_back(passed[neighbors->label]);
            }
        }
        return mynode;
    }
};