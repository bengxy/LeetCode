class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
    	//primes asc order
        priority_queue<long, vector<long>, greater<long>> value;
        value.push(1);

        long res = 0;
        long last = 0;
        int used = 0;
        long max = 0;
        while(n--){
        	res = value.top();
        	if( res == last){
        		value.pop();
        		n++;
        		continue;
        	}
        	last = res;
        //	cout<<res<<endl;
        	for( auto i : primes){
        		long t = res*i;
        		if( used >100 && max<=t){
        			break;
        		}
        		if( max<=t){
        			max = t;
        		}
        		if(){
        			value.push( res * i);
        			used = min(used++, 100)
        		}
        	}
        	
        	value.pop();
        }
        return (int)res;
    }
};
