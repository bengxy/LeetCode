class Solution {
public:
    int firstUniqChar(string s) {
    	if(s=="")
    		return -1;
        int pos[26];
        bool dup[26];
        memset(pos, -1, sizeof(pos));
        memset(dup, false, sizeof(dup));
        for(int i=0;i<s.size();i++){
        	int index = s[i]-'a';
        	if( pos[index]==-1)
        		//dup[index] = true;
        		pos[index] = i;
        	else
        		dup[index] = true;
        }
        int res = INT_MAX;
        for(int i=0;i<26;i++){
        	if(!dup[i] && pos[i]!=-1)
        		if( res > pos[i])
        			res = pos[i];
        }
        return (res==INT_MAX)?-1:res;
    }
};