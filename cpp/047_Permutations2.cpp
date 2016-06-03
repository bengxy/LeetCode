class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        vector<int> buffer;
        build(nums, res, buffer);
        return res;
    }
    void build(vector<int>& nums, vector<vector<int>>& res, std::vector<int>& buffer){
    	if( nums.empty() ){
    		res.push_back(buffer);
    		return ;
    	}
    	for(int i=0;i<nums.size();i++){
    		while( i>0 && i<nums.size() && (nums[i] == nums[i-1]) ){
    			i++;
    		}
    		if( i==nums.size()){
    			return ;
    		}
    		
    		buffer.push_back(nums[i]);
    		nums.erase(nums.begin()+i);

    		build(nums, res, buffer);

    		nums.insert(nums.begin()+i, *(buffer.end()-1));
    		buffer.pop_back();

    	}
    }
};