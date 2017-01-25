/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;
		if( root == NULL)
			return res;
        queue<TreeNode*> memory;
        memory.push(root);

        
        bool reverse = false;
        int levelNum = 1;
        while( !memory.empty() ){
        	vector<int> level;
        	int num = levelNum;
        	levelNum = 0;
        	for(int i=0;i<num;i++){
        		TreeNode* tmp = memory.front();
        		memory.pop();
        		if( tmp ){
        			level.push_back(tmp->val);
        			if(tmp->left) {
        				memory.push(tmp->left);
        				levelNum++;
        			}
        			if(tmp->right){
        				memory.push(tmp->right);
        				levelNum++;
        			}
        		}
        	}
        	if(reverse)
        		std::reverse( level.begin(), level.end() )
        	res.push_back( level );
        	reverse = !reverse;
        }
        return res;
    }
};