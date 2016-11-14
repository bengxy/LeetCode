class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	int rows = matrix.size();
    	int cols=0;
    	if(rows>0){
    		cols = matrix[0].size();
    		if(cols<=0)
    			return false;
    	}
    	else
    		return false;

        int up=0;
        int down = rows-1;
        while(up<=down){
        	int c = (up+down)/2;
        	if( matrix[c][0] <= target && ( c == rows-1 || matrix[c+1][0]>target)  ){
        		int left = 0;
        		int right = cols-1;
        		while(left <= right){
	        		int cc = (left+right)/2;

	        		if( matrix[c][cc] == target )
	        			return true;
	        		else if( matrix[c][cc] < target){
	        			left = cc+1;
	        		}
	        		else{
	        			right = cc-1;
	        		}	
        		}
        		return false;
        	}
        	else if( matrix[c][0]<=target){
        		up = c+1;
        	}
        	else{
        		down = c-1;
        	}
        }
        return false;
    }
};