class Solution {
public:
    int divide(int dividend, int divisor) {

        bool sign = true; // >0
        if( (dividend<0) ^ (divisor<0)  )
        	sign = false; // <0
        if(divisor ==0) return INT_MAX;
        if(divisor == -1 && dividend==INT_MIN)
        	return INT_MAX;

        long ldividend = labs(dividend);
        long ldivisor = labs(divisor);
        
    	
        //if(divisor == 1) return sign?dividend:-dividend;

       

        int res = 0;
        
        while(ldividend>=ldivisor){
        	int count = 1;
        	long tmp = ldivisor;
			while(ldividend >= (tmp<<1) ){
        		count <<= 1;
        		tmp <<= 1;
       		}
       		ldividend -= tmp;
       		res += count;
        }
        return sign?res:-res;
    }
};