class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

    	int left = 0;
    	int right = nums.size()-1;
		int c;
    	while(left<=right){
    		c = (left+right)/2;
    		if( nums[c] == target){
    			break;
    		}
    		else if( nums[c]<target){
    			left = c+1;
    		}
    		else{
    			right = c-1;
    		}
    	}
    	if(left>right)
    		return std::vector<int>({-1,-1});
    	//c is 
    	
    	int buff;
    	std::vector<int> res;
    	left = 0; right = c;
    	while( left<=right){
    		c = (left+right)/2;
    		if(nums[c] == target){
    			buff = c;
    			right = c-1;
    		}
    		else if( nums[c]<target){
    			left = c+1;
    		}
    	}
    	
    	res.push_back(buff);
    	left = c; right = nums.size()-1;
        while( left<=right){
    		int c = (left+right)/2;
    		if(nums[c] == target){
    			buff = c;
    			left = c+1;
    		}
    		else if( nums[c]>target){
    			right = c-1;
    		}
    	}	
    	res.push_back(buff);
    	return res;
	}
};