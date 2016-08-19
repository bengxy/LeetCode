class Solution {
public:
    int hIndex(vector<int>& citations) {
    	citations.sort(std::greater<int>());
        //std::sort(citations.begin(), citations.end());
        int N = citations.size();
        int lhs = 0;
        int rhs = N;
        int h = 0;
        while(true){
        	h = (lhs+rhs)/2;
        	if(citations[h] > h){
        		lhs = h+1;	
        	}
        	else if(citations[h] < h){
        		rhs = h;
        	}
        	
        	

        }
        
    }
};