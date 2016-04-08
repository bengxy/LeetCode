class Solution {
public:
    int trap(vector<int>& height) {
    	if(height.size() < 3) return 0;
    	vector<int> convex;
    	bool acs = true;
    	int pre;
    	int maxpos = 0;
    	for( pre=1;pre< height.size() ;pre++){
    		if ( acs && ( height[pre] < height[pre-1] ) ){
    			
    			convex.push_back(pre-1);
    			if( height[maxpos] < height[pre-1])
    				maxpos = pre-1;
    			acs = false;
    		}
    		else if( !acs && height[pre] > height[pre-1]){
    			acs = true;
    		}
    	}
    	if( height[pre-1] > height[pre-2]){
    		if( height[maxpos] < height[pre-1])
    			maxpos = pre-1;
    		convex.push_back(pre-1);
    	}
    	int water = 0;
    	for( int i=0;i<)
    	/*for( int i = 1;i< convex.size();i++){
    		int left = convex[i-1];
    		int right = convex[i];  		
    		int base = (height[left]>height[right])?height[right]:height[left];
    		for( int j=left+1;j<right;j++){
    			water += (height[j]<base)?(base-height[j]):0;
    		}
    	}*/
    	return water;
    }
};