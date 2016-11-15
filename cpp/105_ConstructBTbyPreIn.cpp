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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        stack<int> stk;

    }
    TreeNode* builder(stack<int>& stk, vector<int>& preorder,int& p, vector<int>& inorder, int& i){
        
        if(preorder[p] != inorder[i]){
            stk.push(preorder[p++]);
            TreeNode* hand = builder(stk, preorder, p, inorder, i);
            if(stk.top() == inorder[i])
        }
        else{
            TreeNode* node = new TreeNode(preorder[i]);
            p++; i++;
            //stk.pop();
        }
        return node;
    } 

};