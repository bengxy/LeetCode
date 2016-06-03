#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    	vector<string> v;
    	string buffer;
    	insertedP(s, buffer, 0 , 4, v);
    	return v;
    }
    void insertedP(string& s, string buffer, int pos, int left, vector<string>& v){
    	if( left == 0 && pos == s.size()){
    		
    		buffer.erase(buffer.size()-1);
    		//cout<<buffer<<endl;
    		v.push_back(buffer);
    		return ;
    	}
    	
    	if( ( (s.size() - pos) > left*3 ) || ((s.size() - pos) < left )){
    		return ;
    	}
    	
    	int split_num = 0;
    	for(int i=pos;i<pos+3&&i<s.size();i++){
    		split_num = 10*split_num + (s.at(i)-'0');
    		if( split_num<256){
    			//cout<<"number"<<split_num<<endl;
    			buffer += s.at(i);
    			//cout<<"buffer"<<buffer<<endl;
    			insertedP(s, buffer+'.', i+1, left-1, v);	
    		}
    		if( s.at(pos) == '0')
    			break;
    	}
    	
    }
};
int main(void){
	Solution a;
	vector<string> x = a.restoreIpAddresses("1230056");
	for(auto i : x){
		cout<<i<<endl;
	}
	return 0;
}