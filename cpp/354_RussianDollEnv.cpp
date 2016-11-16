class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        //sort pair[0] acs  pair[1] desc
        
    	struct{
    		bool operator()(pair<int,int>& a, pair<int, int>& b){
    			if(a[0]<b[0]) return true;
    			else if( a[0]>b[0]) return false;
    			else return a[1]>b[1];
    		}
    	}doll_cmp;
        sort(envelopes.begin(), envelopes.end(), doll_cmp);

        //find longest increase sub seq by pair[1]
    }
};