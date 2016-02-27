class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	if( nums.size() < 3)
    		return nums[0];
    	int maj = 0;
    	int num = 1;
    	//int ind2 = 1;
    	for( int i=1;i<nums.size();i++){
    		if( nums[i] == nums[maj])
    			num++;
    		else if( num > 0)
    			num--;
    		else{
    			maj = i;
    			num = 1;
    		}
    	}
    	return nums[maj];

    }
};