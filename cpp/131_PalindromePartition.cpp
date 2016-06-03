#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        vector<string> buffer;
        builder(s, res, buffer, 0);
	
	for(auto i:res){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}

        return res;
    }
    void builder(string& s, vector<vector<string> >& res, vector<string>& buffer, int pos){
    	if( pos == s.size() ){
    		res.push_back(buffer);
    		return ;
    	}
    	for( int i=1; pos+i-1<s.size();i++){
    		string tmp = s.substr(pos, i);
    		//cout<<tmp<<endl;
    		if ( isPalindrome(tmp) ){
    			buffer.push_back(tmp);
    			builder(s, res, buffer, pos+i);
    			buffer.pop_back();
    		}
    	}
    }
    bool isPalindrome(const string& s){
    	int end = s.size()-1;
    	for( int i=0;i<=end/2;i++){
    		if(s.at(i) != s.at(end-i) )
    			return false;
    	}
    	return true;
    }
};

int main(void){
	Solution a;
a.partition("aab");

	return 0;
}