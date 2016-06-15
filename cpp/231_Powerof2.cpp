//bit: return n>0 && ((n & (n-1)) == 0);
//二进制2的倍数 只有1个1
//例如bi-1000 bi-1 = 0111
//如果 不是二的幂bi的最高1值会不变 n&(n-1) ==1
// 如果是2的幂, 最高1值会被减掉, &之后==0
class Solution {
public:
    bool isPowerOfTwo(int n) {
    	if(n==0) return false;
    	if(n==1) return true;
        while(!(n&0x1)){
			if(n==2)
        		return true;
        	n = n>>1;
        }
        return false;
    }
};