class Solution {
public:
    int titleToNumber(string s) {
    	int res = 0;
        for(int i=0;i<s.size();i++){
        	res = res*26 + s.at(i)-'A'+1
        }
        return res;
    }
};