class Solution {
public:
    vector<int> countBits(int num) {
    	std::vector<int> res(num+1);
    	res.reserve(num+1);
        res[0] = 0;
        for(int i=1;i<=num;i++){
        	res[i] = res[i-pow(2,int(log(i)/log(2)) )]+1;
        }
        return res;
    }
};