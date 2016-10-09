class Solution {
public:
    char findTheDifference(string s, string t) {
    	int x=0;
    	int l = s.size();
    	int i=0;
    	for(;i<l;i++){
    		x^=(int)(s.at(i)-'a');
    		x^=(int)(t.at(i)-'a');
    	}
    	x^=(int)(t.at(i)-'a');
    	return char('a'+x);
    }
};