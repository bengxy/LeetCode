// 把数字按照值 填到数组的index位置
// 扩展： 对于一个值为n~n+k的数组，可以用O(N)的时间复杂度排序
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	for(int i=0;i<nums.size();i++){
    		while(i>0 && nums[i]<=nums.size() && nums[nums[i]-1]!=nums[i]){
    			int tmp = nums[i];
    			nums[i] = nums[nums[i]-1];
    			nums[tmp-1] = tmp;
    		}
    	}
    	for( int i=0;i<nums.size();i++){
    		if(nums[i]!=i+1){
    			return i+1;
    		}
    	}
    	return nums.size()+1;
    }
};