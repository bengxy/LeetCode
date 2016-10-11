class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    int helper(vector<int>& nums, int start, int end ){
    	if( start == end)
    		return nums[start];
    	
    	int center = (start+end)/2;
    	int s = nums[start];
    	int c = nums[center];
    	int e = nums[end];

    	if( c > e)
    		return helper(nums, center+1, end); 
    	else if( c < e){
    		if(s > c)
    			return helper(nums, start, center);
    		else
    			return nums[start];
    	}
    	else{
    		if(s>c)
    			return helper(nums, start, center);
    		else if(s<c)
    			return nums[start];
    		else{
    			int left = helper(nums, start, center);
    			int right = helper(nums, center+1, end);
    			return std::min(left, right);
    		}
    	}
    }
};