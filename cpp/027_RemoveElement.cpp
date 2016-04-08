class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	if( nums.empty() ) return 0;
    	int post = nums.size();
    	int start = 0
    	while(start<post){
    		if( nums[start] == val){
    			post--;
    			if( nums[post] != val){
    				nums[start] = nums[post];
    				start++;
    			}
    			
    		}
    		else{
    			start++;
    		}
    	}
    	return start-1;
    }
};