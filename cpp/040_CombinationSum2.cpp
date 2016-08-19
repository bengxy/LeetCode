class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	vector<vector<int>> res;
    	vector<int> buf;
    	int pos=0;
    	sort(candidates.begin(), candidates.end(), greater<int>());
    	calc_sum(candidates, res, buf, target, pos);
    	return res;
    }
    void calc_sum(vector<int>& candidates, vector<vector<int>>& res, vector<int>& buf, int target, int pos){
    	int last = pos;
    	for(;pos<candidates.size();pos++){
    		if( last < pos && candidates[last] == candidates[pos])
    			continue;
    		last = pos;
    		if(target == candidates[pos]){
	    		buf.push_back(target);
	    		res.push_back(buf);
	    		buf.pop_back();
	    	}
	    	else if(target > candidates[pos]){
	    		buf.push_back(candidates[pos]);
	    		calc_sum(candidates, res, buf, target-candidates[pos], pos+1);
	    		buf.pop_back();
	    	}
    	}
    }
};