/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //循环
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(( p->val == root->val) ||( q->val ==root->val))
    		return root;
    	bool pp = p->val > root->val;
    	bool qq = q->val > root->val;
    	if(pp ^ qq)
    		return root;
    	else if( pp )
    		return lowestCommonAncestor(root->right, p, q);	
    	else
    		return lowestCommonAncestor(root->left, p, q);
    }
};
W:Failed to fetch http://mirrors.zju.edu.cn/ubuntu/dists/utopic/main/source/Sources  404  Not Found [IP: 10.15.61.66 80]