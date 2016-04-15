class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(　prices.size() < 2) return 0;
        int maxProfit = 0;
        int base;
        int lasttop = 0;
        int top = 1;
       	bool clear = true;
        while( top < prices.size() ){
        	if(!clear && (prices[top] < prices[lasttop]) ){
        		maxProfit += prices[lasttop] - prices[base];
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
        	maxProfit+=prices[top-1]-prices[base];
        }
        return maxProfit;
    }
};