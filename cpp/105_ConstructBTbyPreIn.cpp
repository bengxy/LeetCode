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
	int p, i;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	p = 0, i = 0;
    	return builder(preorder, 0, inorder, 0);
    }
    TreeNode* builder(vector<int>& preorder,  vector<int>& inorder){
    	if( p >=preorder.size())
    		return NULL;
    	TreeNode* node = new TreeNode(preorder[p]);

    	if( preorder[p] == inorder[i]){
    		//p+1;i+1;
    		//node->left = NULL;
    		node->right = builder(preorder, p+1, inorder, i+1);	
    	}
    	else{
    		node->left = helper(preorder, p, inorder, i+1);
    		node->right = helper(preorder, p+1, inorder, i+1);
    	}
    	return node;
    }
};