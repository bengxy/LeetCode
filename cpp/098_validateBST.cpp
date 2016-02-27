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
	bool start = true;
	int last;
    bool isValidBST(TreeNode* root) {
    	if(root == NULL) return true;
    	return getNode(root);
    }
    bool getNode(TreeNode* root){
    	bool left, right;
    	if( root->left!= NULL){
    		left = getNode(root->left);
    		if( !left) return false;
    	}
    	if( start){
    		last = root->val;
    		start = false;
    		//return true;
    	}
    	else if( root->val <= last){
    		return false;
    	}
    	else{
    		last = root->val;
    	}
    	if( root->right!= NULL){
    		right = getNode(root->right);
    		if(!right) return false;
    	}
    	return true;
    }
};