class Solution {
public:
    int countPrimes(int n) {
    	bool valid[n];
    	memset(valid, true, n);
    	for( int i=2;i*i<n;i++){
    		if( !valid ) continue;
    		for( int j=i*i;j<n;j+=i){
    			valid[j] = false;
    		}
    	}
    	int count = 0;
    	for( int i=2;i<n;i++){
    		if( valid[i] ) count++;
    	}
    	return count;
    }
};