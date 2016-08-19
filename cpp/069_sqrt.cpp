class Solution {
public:
    int mySqrt(int x) {
    	if(x<1) return 0;
        if(x<4) return 1;
        long lhs = 2;
        long rhs = x;
        int last_min = 2;
        long c;
        int iter = 0;
        while(true){
        	c = (lhs+rhs)/2;
        	//cout<<c<<endl;
        	if(c>50000){
        		//cout<<"m"<<endl;
        		rhs = 50000;
        	}
        	
        	
        	else{
	        	long tmp = c*c;
	        	if(tmp<0 || tmp>INT_MAX){
	        		//cout<<"over"<<endl;
	        		rhs = c;
	        	}
	        	else if(tmp > x){
	        		// if((c-1) == last_min){
	        		// 	c = last_min;
	        		// 	break;
	        		// }
	        		//else{
	        			rhs = c;
	        		//}     			
	        	}
	        	else if( tmp < x){
	        		if((c+1)*(c+1)>x)
	        			break;
	        		lhs = c+1;
	        	}
	        	else{
	        		break;
	        	}
        	}
        }
        return c;
    }
};