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
    bool hasPathSum(TreeNode* root, int sum) {
    	if( root == NULL)
    		return false;
    	int diff = sum-root->val;
    	if( root->left == NULL && root->right == NULL){
    		if(diff == 0)
    			return true;
    		else
    			return false;
    	}
    	else{
    		return hasPathSum(root->left, diff)||hasPathSum(root->right, diff);
    	}	
    }

};