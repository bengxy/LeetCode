class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	if( nums.size() == 0) return 0;
    	if( nums.size() == 1) return target>nums[0]?1:0;
        int start = 0;
        int end= nums.size()-1;
        int center;
        while( start <= end){
        	if( target > nums[end]) return end+1;
        	if( target <= nums[start]) return start;

			center = (start+end)/2;
        	if( nums[center] < target ){
        		start = center+1;
        	}
        	else if( nums[center] > target){
        		end = center;
        	}
        	else
        		return center;
        }
    }
};