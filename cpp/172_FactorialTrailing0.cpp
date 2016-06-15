class Solution {
public:
    int trailingZeroes(int n) {
    	int total = 0;
    	for(;n>=5;n/=5){
    		total = total+n/5;
    	}
    	return total;
    }
};