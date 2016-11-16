class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
    	//edge 4 -> 1
        //edge 5 -> 1 only in the 5 
    				//as line 5 is the same direction of line 1
        //edge 6 -> 1
    	for(int i=3;i<x.size();i++){
    		if( x[i]>=x[i-2] && x[i-1]<=x[i-3])
    			return true;
    		if(i>=5 && x[i-2]-x[i-4]>=0 && x[i]>=x[i-2] - x[i-4] &&\
    		 x[i-1]>=x[i-3] -x[i-5] && x[i-1] <=x[i-3])
    			return true;  
    
            if(i==4 && x[i-1]==x[i-3] && x[i]+x[i-4] >= x[i-2]) 
            	return true; 
   
    	}
    	return false;

    }
};