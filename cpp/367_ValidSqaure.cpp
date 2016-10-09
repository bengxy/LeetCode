class Solution {
public:
	// Newton Method for sqrt
    bool isPerfectSquare(int num) {
    	long tmp = num;
    	while( tmp*tmp > num) {
    		tmp = (tmp+num/tmp) >> 1;
    	}  
    	return tmp*tmp == num;
    }
};