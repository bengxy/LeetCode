class Solution {
public:
    int characterReplacement(string s, int k) {
        int slow = 0;
        int fast = 0;
        int used = k;
        int longest = 0; 
        int cache[26] = {};
        while( fast < s.size() ){
        	cache[s[fast]-'A']++; // cache the char we read
        	if( s[fast]!=s[slow] ){
        		used--; //we replace one
        		if( used == -1) {  //we can not replace more
        			longest = max(longest, fast-slow);
        			//move slow until we can relace further
        			while( slow<fast &&  fast-slow-cache[s[slow]-'A'] >=k     ){
        				//As we have calculate the char at s[slow]
        				//let's move slow to the next different char
        				cache[s[slow]-'A']--;
        				slow++;
        			}
        			used = k-(fast-slow-cache[s[slow]-'A'] +1);
        		}
        	}
        	fast++;
        }
        return max(longest, fast-slow+min(slow, used));
    }
};