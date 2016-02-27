class Solution {
public:
    string convertToTitle(int n) {
    	string res = "";
    	//n = n-1;
    	while( n>0){
    		res = (char)('A'+(n-1)%26) + res;
    		n = (n-1) /26;
    	}
    	return res;
    }
};