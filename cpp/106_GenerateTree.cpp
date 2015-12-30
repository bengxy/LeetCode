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
	int inS = 0;
	int poS = 0;
	stack<int> rootBuff;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	return sel(inorder, postorder);
    }
    TreeNode* sel(vector<int>& inorder, vector<int>& postorder){

		TreeNode* last = NULL;
        while( poS<postorder.size() ){
        	if(!rootBuff.empty() && postorder[poS] == rootBuff.top() ){
    			rootBuff.pop();
    			poS++;
    			return last;
    		}
        	TreeNode* tmp = new TreeNode(inorder[inS]);
			tmp->left = last;
        	last = tmp;
        	if( inorder[inS] == postorder[poS] ){
        		inS++;
        		poS++;
        		continue;
        	}
        	else
        	{
        		rootBuff.push(inorder[inS]);
        		inS++;
        		last->right = sel(inorder, postorder);
        	}
        }
        return last;
    }
};