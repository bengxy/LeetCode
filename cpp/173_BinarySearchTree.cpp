/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> stk;
    void build_index(TreeNode* index){
        while( index!=NULL){
            stk.push(index);
            index = index->left;
        }
    }
public:
	
    BSTIterator(TreeNode *root) {
    	build_index(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        //if( !hasNext() ) return -1;
        TreeNode* cur = stk.top();
        stk.pop();

        build_index(cur->right);
        
    	return cur->val;
    }

};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */