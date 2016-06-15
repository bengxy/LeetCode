
class Solution {
public:
    string largestNumber(vector<int>& nums) {
    	if(nums.empty())
    		return "";
        sort(nums.begin(), nums.end(), comp);
        string buf = "";
        bool all_zero=true;
        for(auto i :nums){
        	if(i!=0)
        		all_zero=false;
        	buf+=to_string(i);
        }
        return all_zero?"0":buf;
        
    }

    static bool comp(int a, int b){
    	//a longer
    	if( a==b )
    		return false;
    	string as = to_string(a);
    	string bs = to_string(b);
    	if( as.size() < bs.size() )
    		return !comp(b, a);

    	int len = as.size();
    	int lb = bs.size();
    	int i = 0;
    	int j = 0;
    	while (i<len){
    		if( as.at(i)==bs.at(j) ){
    			i++;
    			j=(j+1)%lb;
    			continue;
    		}
    		return as.at(i)>bs.at(j);
    	}
    	i=0;
    	while(j<lb){
    		if( as.at(i) ==bs.at(j)){
    			i++;j++;
    			continue;
    		}
    		return as.at(i)>bs.at(j);
    	}

    	return false; 	
    }
};