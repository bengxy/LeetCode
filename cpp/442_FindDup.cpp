class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    	vector<int> res;
        for(int i=0;i<nums.size();i++){
        	int v = (nums[i]>0?nums[i]:-nums[i])-1;
        	if(nums[v] > 0)
        		nums[v] = -nums[v];
        	else
        		res.push_back(v+1);
        }
        return res;
    }
};