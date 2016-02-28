class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int pri = 0;
        int post = nums[0];
        int buff = nums[1];
        int max = buff>post?buff:post;
        if(nums.size() == 2)
        	return max;

        for(int i=2;i<nums.size();i++){
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