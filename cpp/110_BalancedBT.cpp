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
    bool isBalanced(TreeNode* root) {
    	int res = depth(root);
    	return res==-1?false:true;
    }
    int depth(TreeNode* root){
    	if(root==NULL) 
    		return 0;
    	int ldepth = root?depth(root->left):0;
        int rdepth = root?depth(root->right):0;
        if(ldepth==-1 || rdepth==-1)
        	return -1;
        else if( abs(ldepth-rdepth) > 1)
        	return -1;
        else
        	return max(ldepth, rdepth)+1;
    }
};