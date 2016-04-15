class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) 
            return 0;
        int maxpro = 0;
        int base;
        int lasttop = 0;
        int top = 1;
       	bool clear = true;
        while( top < prices.size() ){
        	if(!clear && (prices[top] < prices[lasttop]) ){
        		maxpro += prices[lasttop] - prices[base];
        		clear = true;
        	}
        	else if( clear && (prices[top] > prices[lasttop])){
        		base = lasttop;
        		clear = false;
        	}

        	lasttop = top;
        	top++;
        }
        if(!clear){
        	maxpro+=prices[top-1]-prices[base];
        }
        return maxpro;
    }
};