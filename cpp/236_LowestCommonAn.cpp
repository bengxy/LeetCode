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


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        	bool v1,v2;
        	v1 = v2 = false;
        	return DFS(root, p, q, v1, v2);

    }
    TreeNode* DFS(TreeNode* root, TreeNode* p, TreeNode* q, bool& vp, bool& vq){
    	if( root == NULL)
    		return NULL;
    	if(vp || vq){
    		//find 1;
    		    if( !vp && root->val == p->val){
		    		vp = true;
		    	}
		    	if( !vq && root->val == q->val){
		    		vq = true;
		    	}
		    if( vp && vq){
		    	return root;
		    }
		    else{
		    	TreeNode* r1 = DFS(root->left, p, q, vp, vq);
		    	if(r1 == NULL){
		    		TreeNode* r2 = DFS(root->right, p, q, vp, vq);	
    				if(r2 == NULL)
    					return NULL;
    				else
    					return root;
		    	}
		    	else
		    		return root;
		    }
    	}
    	else{
    		TreeNode* r1 = DFS(root->left, p, q, vp, vq);
    		if( vp && vq){
    			return r1;
    		}
    		else{
    			
    			if(vp || vq){
    				return root;	
    			}
    			else{
    			TreeNode* r2 = DFS(root->right, p, q, vp, vq);	
    			
    				return r2;
    			
    			}
    		} 
    		
    	}
    	
    }
};
