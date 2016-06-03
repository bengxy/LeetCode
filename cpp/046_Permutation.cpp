class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> buffer;
        build(nums, res, buffer);
        return res;
    }
    void build(vector<int>& nums, vector<vector<int>>& res, vector<int>& buffer){
    	if( nums.empty()){
    		res.push_back(buffer);
    		return ;
    	}
    	for( int i=0;i<nums.size();i++){
    		//delete
    		int tmp = nums[i];
    		
    		buffer.push_back(tmp);
    		
    		nums.erase(nums.begin()+i);
    		build(nums, res, buffer);
    		//insert
    		nums.insert(nums.begin()+i, tmp);
    		buffer.pop_back();
    		
    	}
    }
};