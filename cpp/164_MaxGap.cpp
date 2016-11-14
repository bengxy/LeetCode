//Bucket sort by bit
class Solution {
public:
	void bucketsort(vector<int>& nums, int s, int e, int d){
		if(d<0 || s==e)
			return ;
		int cursor = s;
		for(int i=s;i<e;i++){
			if(nums[i] & (1<<d)){
				swap(nums[cursor], nums[i]);
				cursor++;
			}
		}
		bucketsort(nums, s, cursor, d-1);
		bucketsort(nums, cursor, e, d-1);
	}
    int maximumGap(vector<int>& nums) {
    	bucketsort(nums, 0, nums.size(), 31);
    	int gap =0;
    	for( int i=1;i<nums.size();i++){
    		gap = max(gap, nums[i-1]-nums[i]);
    	}
    	return gap;
    }
};