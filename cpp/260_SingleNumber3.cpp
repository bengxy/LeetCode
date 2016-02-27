//divide conquer
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    	if( nums.empty()){
    		return nums;
    	}
    	int xorRes = 0;
        for( auto num : nums)
        	xorRes ^= num;
        //get the total xor Value
        int index = 0;
        while( (xorRes & ( 1<<index ) ) ==0 ){
        	index++;
        	if( index > 31)
        		break;
        }
        int checkBit = 1<<index;
		int part0 = 0;
		int part1 = 0;
        for( auto num: nums){
        	if( num & checkBit ){
        		part0 ^= num;
        	}
        	else{
        		part1 ^= num;
        	}
        }
        std::vector<int> res = {part0, part1};
        return res;
    }
};