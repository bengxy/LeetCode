class Solution {
public:
    string countAndSay(int n) {
    	if( n==1){
    		return "1";
    	}
    	string s = countAndSay(n-1);
    	string res="";
    	int left = 0;
    	int right =0 ;
    	while( left < s.size() ){


    		while( right < s.size() && (s.at(right) == s.at(left)) )
    			right++;
    		res += to_string(right-left)+s.at(left);
    		left = right;
		}
        return res;
    }
};