class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if( nums.size() < 2)
        	return nums.size();

        int now = 0;
        int last = 1;
        int d = 0;
        while( last<nums.size()){
        	if( nums[last] == nums[now]){
        		last++;
        	}
        	else{
        		nums[++now] = nums[last++];
        	}
        }
        return now+1;
    }
};