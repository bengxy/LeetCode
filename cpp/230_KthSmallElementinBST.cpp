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
	bool find = false;
	int val;
    int kthSmallest(TreeNode* root, int k) {
    	bst(root, k);
    	return val;
    }
    void bst(TreeNode* root, int& k){
    	if( root == NULL )
    		return ;
    	bst(root->left, k);
    	if( find )
    		return ;
    	k--;
    	if( k==0 ){
    		find = true;
    		val = root->val;
    		return ;
    	}
    	bst(root->right, k);
    	if( find )
    		return ;
    }

};