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
    vector<vector<int> v;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        hasPathSum(root);
        return v;
    }
    int hasPathSum(TreeNode* root, int sum) {
    	if( root == NULL)
    		return 0;
    	int diff = sum-root->val;
    	if( root->left == NULL && root->right == NULL){
    		if(diff == 0){
                vector<int> tmp;
                tmp.push_back(root->val);
                v.push_back(tmp);
                return 1;
            }
    		else
    			return 0;
    	}
    	else{
            int total = hasPathSum(root->left, diff)+hasPathSum(root->right, diff);

            if(total == 0 ){
                return 0;
            }
            else{

                for(int i=0;i<total;i++){
                    auto iter = v[v.size()-i-1].begin();
                    v[v.size()-i-1].insert(iter, root->val);
                }
                
            }
    	}	
    }

};