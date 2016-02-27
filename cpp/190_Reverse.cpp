#include <iostream>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    	uint32_t res = 0;
    	
    	for(int i=0;i<32;i++){
    		res = res<<1;
    		res += n%2;
        	n = n>>1;
    	}
    	
    	return res;
        
    }
};
int main(void){
	Solution s;
	uint32_t x = 43261596;
	cout<<s.reverseBits(x)<<endl;
	return 0;
}