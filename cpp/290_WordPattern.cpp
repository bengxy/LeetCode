class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        int l = pattern.size();
        int sl = str.size();
        int begin = 0;
        int pos = 0;
        for(int i=0;i<l;i++){
        	if(begin == 0 && pos == string::npos)
        		return false;

        	pos = str.find_first_of(' ', begin);
        	//cout<<begin<<' '<<pos<<endl;
        	string substr = str.substr(begin , pos-begin);

        	begin = pos+1;
        	//cout<<substr<<endl;
        	if( m1.find(pattern[i]) != m1.end() && m1[pattern[i]] !=substr ){
        		return false;
        	}
        	if( m2.find(substr) != m2.end() && m2[substr] != pattern[i]){
        		return false;
        	}
        	m1[pattern[i]] = substr;
        	m2[substr] = pattern[i];
        }
        if( begin == 0 && pos == string::npos)
        	return true;
        else
        	return false;
    }
};