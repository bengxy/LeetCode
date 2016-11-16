class Solution {
public:
    int jump(vector<int>& nums) {
    	if( nums.size() < 2 ) return 0;
    	if( nums.size() == 2) return 1; //alwayse reach
        int start = 0;
        int end = 1;
        int step = 0;
        while(end<nums.size()){
            if( start>end) return -1; // exception

            int new_end = end;
        	for(int i=start;i<end;i++){
        		int bound = i+nums[i]+1;
                
        		if(bound > new_end){
        			new_end = bound;
        			if(new_end >= nums.size())
        				break;
        		}
        	}
            start = end;
            end = new_end;
        	
        	step++;
        }
        return step;
    }
};