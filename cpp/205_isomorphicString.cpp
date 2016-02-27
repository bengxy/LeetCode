class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	if( s.size() != t.size() )
    		return false;
 		unordered_map<char, char> x;
 		unordered_map<char, char> y;
 		for(int i=0;i<s.size();i++){
 			if( x.find(s.at(i)) == x.end() ){
 				x[s.at(i)] = t.at(i);
 			}
 			else{
 				if( x[s.at(i)]!=t.at(i))
 					return false;
 			}
 			if( y.find(t.at(i)) == y.end() ){
 				y[t.at(i)] = s.at(i);
 			}
 			else{
 				if( y[t.at(i)]!=s.at(i))
 					return false;
 			}
 		}
 		return true;

    }
};