class Solution {
public:
	void helper(vector<vector<int>>& res, vector<int>& nums, int pos){
		cout<<pos<<endl;
		int end = res.size();
		int start = 0;
		while( pos<nums.size() ){
			for(int i=start;i<end;i++){
				vector<int> tmp(res[i]);
				tmp.push_back(nums[pos]);
				res.push_back(tmp);
			}
			start = end;
			end = res.size();
			pos++;
			if( pos == nums.size() || nums[pos] != nums[pos-1])
				break;
		}
		if( pos == nums.size() ) return ;
		helper(res, nums, pos);
	}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> already;
        res.push_back(already);
        helper(res, nums, 0);
        return res;
    }	
};
