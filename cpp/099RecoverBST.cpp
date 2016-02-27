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
	TreeNode* last;
	TreeNode* err1 = NULL;
	TreeNode* err2 = NULL;
    void recoverTree(TreeNode* root) {
    	if( root == NULL || (root->left == NULL && root->right ==NULL))
    		return;
    	TreeNode* tmp = root;
    	while( tmp->left!=NULL){
    		tmp = tmp->left;
    	}
    	last = tmp;
        checkDFS(root);
        int val = err1->val;
        err1->val = err2->val;
        err2->val = val;
    }
    void checkDFS(TreeNode* root){
    	if( root == NULL)
    		return ;
    	checkDFS( root->left);
    	if( root->val < last->val){
    		if( err1 == NULL ){
    			err1 = last;
    			err2 = root;
    		}
    		else
    			err2 = root;
    	}
    	last = root;
    	checkDFS(root->right);
    }
};