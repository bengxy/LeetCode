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
    bool isSymmetric(TreeNode* root) {
    	if( root == NULL)
    		return true;
    	else
    		return twoSym(root->left, root->right);
    }
	bool twoSym(TreeNode* left, TreeNode* right){
		if(left == NULL && right == NULL){
			return true;
		}
		else if( left!= NULL && right!=NULL){
			return (left->val == right->val) &&\
				 twoSym(left->left, right->right) &&\
				 twoSym(left->right, right->left);
		}
		else
			return false;
	}
};