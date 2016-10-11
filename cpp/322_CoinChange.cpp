class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	sort(coins.begin(), coins.end());
    	if(amount==0) return 0;
    	int last = coins.size()-1;
    	return dp(coins, amount, last, INT_MAX);
    }
private:
	//int count;
    int dp(vector<int>& coins, int amount, int last, int Lmin){
    	if(last<0)
    		return -1;
    	//cout<<"Amount "<<amount<<"last "<<last<<"Limin "<<Lmin<<endl;
    	int min = Lmin;   
    	if(amount < coins[last]){
    		return dp(coins, amount, last-1, min);
    	}
    	// amount > coins[last]
    	int all = amount/coins[last];
    	// 	return -1;
    	if( all> Lmin)
    			return -1;
    	if(amount%coins[last] == 0){
    		return all;
    	}
    	// not 0
    	for(int i=all;i>=0;i--){
    		//cout<<i<<endl;

    		//cout<<"check_1 "<<min<<endl;
    		int res = dp(coins, amount-i*coins[last], last-1, min);
    		if((res != -1) &&((res+i)<min)){
    			min = res+i;
    		} 
    		//cout<<"check_2 "<<min<<endl;
    	}
    	return min==Lmin?-1:min;
    }
};