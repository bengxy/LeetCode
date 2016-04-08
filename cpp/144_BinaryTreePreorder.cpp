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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> v;
        vector<int> res;
        //TreeNode* tmp = root;
        while(root){
        	res.push_back(root->val);
        	if( root->left != NULL){
        		if( root->right!=NULL){
        			v.push(root->right);
        		}
        		root = root->left;
        	}
        	else{
        		if( root->right == NULL){
        			if( v.empty() ){
        				break;
        			}
        			else{
        				root = v.top();
        				v.pop();
        			}        			
        		}
        		else{
        			root = root->right;
        		}
        	}
        }
        return res;
    }
};