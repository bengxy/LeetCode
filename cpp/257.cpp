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
	vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
    	if(root != NULL){
        	string inits = "";
        	deepFirst(root, inits);
        }
        return res;
    }
    void deepFirst(TreeNode* root, string s){
    	if( root-> left == NULL && root->right == NULL){
    		s += std::to_string(root->val);
    		res.push_back(s);
    	}
    	else{
    		s += std::to_string(root->val)+"->";
    		if(root->left!=NULL)
    			deepFirst(root->left, s);
    		if(root->right!=NULL)
    			deepFirst(root->right, s);
    	}
    }
};