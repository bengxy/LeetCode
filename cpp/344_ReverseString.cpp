

class Solution {
public:
    string reverseString(string s) {
    	int a = s.size()-1;
        int half = (a+1)/2;
		
		for(int i=0;i<half;i++){
			char t = s[i];
			s[i] = s[a-i];
			s[a-i] = t;
		}
		return s;
    }
};