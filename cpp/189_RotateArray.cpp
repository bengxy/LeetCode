class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    	k = k%nums.size();
    	if( k ==0)
    		return;
    	reverse(nums, 0, nums.size()-k);
    
    	reverse(nums, nums.size()-k, nums.size());
    
    	reverse(nums, 0, nums.size());
    	
    }
    void reverse(vector<int>& nums, int start, int end){
    	int center = (end-1+start)/2;
    	for(int i=start;i<=center;i++){
    		int tmp = nums[i];
    		nums[i] = nums[end-i+start-1];
    		nums[end-i+start-1] = tmp;
    	}
    }
};