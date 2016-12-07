class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int l = nums.size();
    	if(l < 2 )
    		return l;
    	int cnt = 0;
    	bool last_state = !(nums[1]>nums[0]);
        for(int i=1;i<l;i++){
        	if( nums[i]==nums[i-1] )
        		continue;
        	if(cnt == 0) //initial
        		last_state = !(nums[i]>nums[i-1]);
        	
        	
        	if( last_state != (nums[i] > nums[i-1] )){
        		cnt++;
        		last_state  =!last_state;
        	}
        }
        return cnt+1;
    }
};