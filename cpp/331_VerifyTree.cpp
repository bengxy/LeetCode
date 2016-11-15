class Solution {
public:
    bool isValidSerialization(string preorder) {
    	int i = 0;
    	int degree = 1;
    	while( i< preorder.size() ){
    		if( --degree < 0)
    			return false;
    		if( preorder[i] != '#')
    			degree += 2;
    		while(i<preorder.size() && preorder[i++]!=',') ;
    	}
    	return degree == 0; //balance
    }
};