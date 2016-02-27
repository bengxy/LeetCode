class Solution {
public:
    vector<int> grayCode(int n) {
    	int total = 1<<n;
        vector<int> res(total);
        res[0] = 0;
        if(n == 0)
        	return res;
        for(int i=1;i<total;i*=2){
        	for(int j=i;j<i*2;j++){
        		res[j] = res[i*2-j-1] + i;
        		//res[j] = res[i*2 - j - 1] + i;	
        	}
        }
        return res;
    }
};