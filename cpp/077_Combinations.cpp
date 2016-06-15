
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if( k==0 || n == 0 || k>n)
        	return res;
        vector<int> buffer;
        helper(res, buffer, 1, n+1, k);
        return res;
    }

    void helper(vector<vector<int>>& res,vector<int>& buffer, int start, int end, int k){
    	if( k == 0){
    		res.push_back(buffer);
    		return ;
    	}
    	if( (end-start) < k){
    		return ;
    	}
    	for( int i=start;i<end-k+1;i++){
    		buffer.push_back(i);
    		helper(res, buffer, i+1, end, k-1);
    		buffer.pop_back();
    	}
    } 
};
