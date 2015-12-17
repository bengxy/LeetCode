class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int res = 0;
    	for(auto iter=nums.begin();iter!=nums.end();iter++){
    		res = res^*iter;
    	}   
    	return res;
    }
};