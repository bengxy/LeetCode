class Solution {
public:
    bool canJump(vector<int>& nums) {
    	if(nums.empty())
    		return false;
    	if(nums.size()==1)
    		return true;

    	int index = nums.size()-2;
    	
    	while(index>=0){
    		if( nums[index] == 0){
    			int zero=index;
    			while(index>=0 && nums[index]<=(zero-index) ){
    				index--;
    				
    			}
    			if(index<0)
    				return false;
    			else
    				index--;
    		}
    		else
    			index--;
    	}
    	return true;
    }

};