class Solution {
public:
    string convert(string s, int numRows) {
    	// 0 1 2 3    4 5   6789 10 11 
    	int center = numRows-1;
    	int skip  = 2*numRows-2;
    	int col = s.length()/skip+1;
		string res = "";
		for(int i=0;i<s.length();i+=skip){
			res += s.at(i);
		}
		for (int j = center-1; j>0; j--){
    		for (int i = center; ; i+=skip){
    			if( (i-j)<s.length() )
    				res += s.at(i-j);
    			else
    				break;
    			if( (i+j)<s.length() )
    				res += s.at(i+j);
    			else
    				break;
    		}
    	}
    	for (int i = center; i < s.length(); i+=skip){
    		res += s.at(i);
    	}



    }
};