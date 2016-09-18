class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty() || nums.size()==1)
        	return 0;
        else if(nums.size()==2){
        	return nums[0]>nums[1]?0:1;
        }

        int l = 0;
        int r = nums.size()-1;
        while(r>=l){
        	int c = (l+r)/2;
        	if(c==0||c==nums.size()-1)
        		return c;
        	int front = nums[c-1];
        	int back = nums[c+1];
        	if(front<nums[c] && back<nums[c])
        		return c;
        	else if(front>nums[c]){
        		r = c;
        	}
        	else{
        		l = c+1;
        	}
        }
        return 0;
    }
};