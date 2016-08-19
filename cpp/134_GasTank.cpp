class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    	int l = gas.size();
    	if(l==0)
    		return -1;
    	int start = 0;
    	int i = start;
    	int sum_gas = 0;
    	int sum_cost = 0;

    	int iter = 0;
    	while(iter<l){
    		sum_gas  += gas[i%l];
    		sum_cost += cost[i%l];
    		if(sum_gas < sum_cost){
    			sum_cost = sum_gas = 0;
    			iter = 0;
    			start = i+1;
    			if( start >= l)
    				return -1;
    			i = start;
    			continue;
    		}
    		i++;
    		iter++;
    	}
    	return start%l;
    }
};