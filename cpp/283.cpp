class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int left = 0;
    	int right = 0;
    	int end = nums.size();
    	while(left < end){
    		if( nums[left] == 0){
    			left++;
    		}
    		else{
    			if(left!=right)
    				nums[right] = nums[left];
    			left++;right++	
    		}
    	}

    }
};