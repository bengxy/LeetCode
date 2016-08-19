// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long rhs = n;
        long lhs = 1;
        long g=0;
        while(true){
        	//g = (lhs/2+rhs/2)+(lhs%2==1 && rhs%2==1)?1:0;
        	g = (lhs+rhs)/2;
        	int res = guess(g);
        	if(res == 1)
        		lhs = g+1;
        	else if(res == -1)
        		rhs  = g;
        	else
        		break;
        	
        }
        return g;      
    }
};