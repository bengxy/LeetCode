class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if( prices.size() < 2)
        	return 0;
        int min = prices[0];
        int maxpro = 0;
        int tmppro;
        for(int i=1;i<prices.size();i++){
        	tmppro = prices[i] - min;
        	if(tmppro > maxpro)
        		maxpro = tmppro;
        	if( prices[i] < min)
        		min = prices[i];
        }
        return maxpro;
    }
};