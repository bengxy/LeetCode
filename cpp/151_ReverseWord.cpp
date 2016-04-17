#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
    	int total = s.size();
		int center  = total/2;
        for(int i=0;i<center;i++){
        	char tmp = s.at(i);
        	s.at(i) = s.at(total-i-1);
        	s.at(total-i-1) = tmp;
        }
        
    }
};

int main(void){
	Solution a;
	string x = "abc def ghi";
	a.reverseWords(x);
	cout<<x<<endl;
}