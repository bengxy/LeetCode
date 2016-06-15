class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if(nums.size()<3)
        	return 0;
        int len = nums.size();
        int distance = nums[len-1]+nums[len-2]+nums[len-3];
        int cls = 0;
        bool acs = true;
        for(int i=0;i<nums.size()-2;i++){
        	if( nums[i] > target){
        		break;
        	}
        	cls = Closest(nums, target);

        }
        return distance;
    }
    int Closest(std::vector<int>& nums, int target){
    	
    }
};