class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        if( len < 2)
        	return 0;
        int MAX = 0;
        vector<int> bits;
        for( auto i : words){
        	bits.push_back( str2bit(i) );
        }
        for( int i=0;i<bits.size();i++){
        	for( int j=i+1;j<bits.size();j++){
        		if( (bits[i] & bits[j]) != 0)
        			continue;
        		int tmp_max = words[i].size() * words[j].size();
        		
        		
        		MAX = tmp_max>MAX?tmp_max:MAX;
        	}
        }
        return MAX;
    }
    int str2bit(const string& s){
    	int bit = 0;
    	for(auto i:s){
    		bit = bit | (1<<(i-'a'));
    	}
    	return bit;
    }
	
};