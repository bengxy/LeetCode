class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	//candidates.sort();
    	std::sort(candidates.begin(), candidates.end());
    	std::vector<std::vector<int>> res;
    	vector<int> already;
    	rcv( candidates, res, 0, target, already);
    	return res;
    }
    void rcv(vector<int>& candidates, vector<vector<int>>& res, int start, int target, vector<int>& already){
    	if( target < 0) return ;
    	else if( target == 0){
    		res.push_back(already);
    	}
    	for( int i = start;i<candidates.size();i++){
    		already.push_back(candidates[i]);
    		rcv( candidates, res, i, target - candidates[i], already);
    		already.pop_back();
    	}
    }
};