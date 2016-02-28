class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    	vector<string> res;
    	if( nums.empty()) return res;
    	int start = 0;
    	int end = start;
    	for( int i=1;i<nums.size();i++){
    		if(nums[i] != nums[end]+1){
    			string tmp = (start==end)?std::to_string(nums[start]):\
    			(std::to_string(nums[start])+"->"+std::to_string(nums[end]));
    			start = i;
    			end = i;
    			res.push_back(tmp);
    		}
    		else{
    			end++;
    		}
    	}
    	string tmp = (start==end)?std::to_string(nums[start]):\
    			(std::to_string(nums[start])+"->"+std::to_string(nums[end]));
		res.push_back(tmp);
		return res;
    }
};