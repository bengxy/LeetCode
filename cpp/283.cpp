class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	//merge 
    	merge(nums, 0, nums.size()-1);

    }
    int merge(vector<int>& nums, int start, int end){
    	if( nums.size() == 1){
    		return 0;
    	}
    	else{
    		int center = (start+end)/2;
    		int lsep = merge(nums, start, center);
    		int rsep = merge(nums, center+1, end);
    		//TODO: merge two
    	}
    }
};