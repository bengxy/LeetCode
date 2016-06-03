class Solution {
public:
    int lengthOfLastWord(string s) {
    	s.erase(0,s.find_first_not_of(" "));  
    	s.erase(s.find_last_not_of(" ") + 1);  
    	int i;
    	for(i=s.size()-1;i>=0;i--){
    		if( s.at(i) == ' ')
    			return s.size()-i-1;
    	}
    	return s.size()-i-1;

    }
};