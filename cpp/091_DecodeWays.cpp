class Solution {
public:
    int numDecodings(string s) {
        int skip1, skip2;
        if( s.size() == 1) return 1;
        if( s.size() == 2){
        	if( s<="26" && s.at(1)!='0') return 2;
        	else return 1;
        } 
        
    }
};