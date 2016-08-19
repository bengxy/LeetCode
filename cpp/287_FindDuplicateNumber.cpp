//两种方法:
//1. bi-search  1~N 分成 1~2/n 2/n~n的两块的数量，看冗余项在哪个
//2. Linear  类似于找到一个loop link的起点问题，一个快指针跑两步
//	因为在1~n的鸽巢问题中，必然存在index的loop；
//  正常情况下 1~n数放到index是0~n-1的里面，不会有loop因为每个index都有唯一的value指向它
//  但是鸽巢问题有一个index被多个value指向，所以会出现loop
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    	if(nums.size() < 2)
    		return -1;
    	int slow = nums[0];
    	int fast = nums[nums[0]];
    	while(slow!=fast){
    		slow = nums[slow];
    		fast = nums[nums[fast]];
    	}
    	fast = 0;
    	while(slow!=fast){
    		slow = nums[slow];
    		fast = nums[fast];
    	}
    	return slow;

    }

};