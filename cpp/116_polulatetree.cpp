/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	root->next = NULL;
    	if(root==NULL)
    		return;
        link(root->left, root->right);
    }
    void link(TreeLinkNode *left, TreeLinkNode *right){
    	
    	if(left!=NULL){
    		link(left->left, left->right);
    		link(right->left, right->right);
    	}
    	else
    		return;

    	while(left!=NULL){
    		if(right!=NULL){
    			left->next = right;
    			//right->next = NULL;
    			right = right->left;
    		}
    		else{
    			left->next = NULL;
    		}
    		left = left->right;
    	}
    }
};