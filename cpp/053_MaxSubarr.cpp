class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	if(nums.empty())
    		return 0;
    	int l = nums.size();
	    int max = nums[0];
    	int tmp = 0;
        for(int i=0;i<l;i++){
        	tmp = tmp+nums[i];
        	if(tmp>max)
        		max = tmp;
        	if(tmp<0)
        		tmp = 0;
        }
        return max;
    }
};