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
	int maxdeep;
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        maxdeep = 0;
        rdf(root, res, 1);
        return res;
    }
    void rdf(TreeNode* root, vector<int>& res, int deep){
    	if(root==NULL)
    		return ;
    	if(deep>maxdeep){
    		res.push_back(root->val);
    		maxdeep = deep;
    	}
    	rdf(root->right, res, deep+1);
    	rdf(root->left, res, deep+1);
    }
};