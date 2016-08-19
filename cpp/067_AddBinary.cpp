class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i = a.size()-1;
        int j = b.size()-1;
        char c = '0';
        while(i>=0 && j>=0){
        	ans += (a.at(i)=='1' ^ b.at(j)=='1' ^ c=='1')?'1':'0';
        	if((c=='1' && (a.at(i)=='1' || b.at(j)=='1') ) ||
        		(a.at(i)=='1'&&b.at(j)=='1') ){
        		c = '1';
        	}
        	else
        		c = '0';
        	i--;j--;
        }
        if( i<0){
        	i = j;
        	a = b;
        }
        while(i>=0){
        	ans += (a.at(i) ^ c)?'1':'0';
        	c = (a.at(i)=='1' && c=='1')?'1':'0';
        	i--;
        }
        if(c=='1')
        	ans+='1';
        std::reverse(ans.begin(), ans.end());
        return ans;

    }
};