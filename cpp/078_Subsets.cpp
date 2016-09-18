class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(tmp);
        helper(res, nums, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& nums, int idx){
    	if(idx>=nums.size())
    		return ;
    	int l = res.size();
    	for(int i=0;i<l;i++){
    		vector<int> tmp = res[i];
    		tmp.push_back(nums[idx]);
    		res.push_back( tmp );
    	}
    	helper(res, nums, idx+1);
    }
};