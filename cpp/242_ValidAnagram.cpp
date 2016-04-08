class Solution {
public:
    bool isAnagram(string s, string t) {
    	//if( s=="" && t=="") return true;
    	if( s.size() != t.size() ) return false;
        char m[26];
        memset( m, 0, 26);
        //bool res = true;
        for(int i=0;i<s.size();i++){
        	m[s.at(i)-'a']++;
        	m[t.at(i)-'a']--;
        }
        for( int i=0;i<26;i++){
        	if( m[i] != 0 ) return false;
        }
        return true;
    }
};