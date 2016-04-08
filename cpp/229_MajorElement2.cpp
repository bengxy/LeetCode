class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    	//2 cell
    	vector<int> res;
    	
    	//else if( nums.size())
    	int c1, c2;
    	//c1 = c2 = 0;
    	int n1, n2;
    	short state = 0x00;
    	//x = y = false;
    	for( int i: nums){
    		switch(state){
    		case 0x00:
    			n1 = i; c1  = 1; state = 0x01;
    			break;
    		case 0x01:
    			n2 = i; c2 = 1; state = 0x11;
    			break;
    		case 0x10:
    			n1 = i; c1 = 1; state = 0x11;
    			break;
    		case 0x11:
    			if( n1 == i){
    				c1+=2; c2--;
    			}
    			else if(n2 == i){
    				c2+=2; c1--;
    			}
				else {
					c1--; c2--;
    			}
    			if( c1 == 0) state &= 0x10;
				if( c2 == 0) state &= 0x01;
    			break;
    		default: break;
    		}
    	}


    	cout<< c1 << " "<< n1<<endl;
    	cout<< c2<<" "<<n2<<endl;
    	switch( state ){
    	case 0x00:
    		return res;
    	case 0x01:
    		res.push_back(n1); return res;
    	case 0x10:
    		res.push_back(n2); return res;
    	case 0x11:
    		res.push_back(n1);
    		res.push_back(n2);
    		return res;
    	default : return res;
    	}
    }
};