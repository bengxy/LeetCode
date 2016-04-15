class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while( left < right){

        	int center = (left+right)/2;
        	if( nums[center] == target ) return center;
        	else if(target > nums[center]){
        		if( target > nums[right] && nums[center] < nums[right]){
        			right = center;
        		}
        		else{
        			left = center+1;
        		}
        	}
        	else{
        		if(target < nums[left] && nums[center] > nums[right]){
        			left = center+1;
        		}
        		else{
        			right = center;
        		}
        	}
        }
        while(left < right){
        	int center = (left+right)/2;
        	if(nums[center]<target)
        		left = center+1;
        	else
        		right = center;
        }
        if( nums[left] == target) return left;
        else return -1;
        
    }
};