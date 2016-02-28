class Solution {
public:
	  vector<string> mu = {
        	"abc",
        	"def",
        	"ghi",
        	"jkl",
        	"mno",
        	"pqrs",
        	"tuv",
        	"wxyz"
        };
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string last = "";
        int index = 0;
        if( !digits.empty())
        	already(res, digits, index, last);
        return res;
    }
    void already(vector<string>& res, string digits, int index, string last){
    	if( index == digits.size() ){
    		res.push_back( last );
    		return ;
    	}
    	string keyStr = mu[digits.at(index)-'2'];
    	for( char c: keyStr){
    		already(res, digits, index+1, last+c);	
    	}
    	
    }
};

