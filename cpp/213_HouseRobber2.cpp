class Solution {
public:
    int rob(vector<int>& nums) {
     	if(nums.empty()) return 0;
     	if(nums.size() == 1) return nums[0];
     	int max1 = nums[0];
     	int max2 = nums[1];
        if(nums.size() > 3) {
        	max1 = robList(nums, 0, nums.size()-1);
     	  	max2 = robList(nums, 1, nums.size());
     	  	return max1>max2?max1:max2;
    	}
    	int max = max1>max2?max1:max2;
        if(nums.size() == 2)
        	return max;
        return max>nums[2]?max:nums[2];
    }
    int robList(vector<int>& nums, int start, int end) {
    	//>3
        int pri = 0;
        int post = nums[start];//int post = nums[0];
        int buff = nums[start+1];//int buff = nums[1];
        int max = buff>post?buff:post;
       /* if(nums.size() == 2)
        	return max;
        */
        for(int i=start+2;i<end;i++){
        	int a = pri+nums[i];
        	int b = post+nums[i];
        	int tmp = a>b?a:b;
        	if(tmp > max) max = tmp;
        	pri = post;
        	post = buff;
        	buff = tmp;
        }
        return max;
    }

};