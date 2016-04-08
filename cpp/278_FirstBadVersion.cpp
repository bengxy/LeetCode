// Forward declaration of isBadVersion API.
bool isBadVersion(int version);


class Solution {
public:
    int firstBadVersion(int n) {
        if( n < 2) return n;
        int left = 1;
        int right = n;
        int center = left+(right-left)/2;
        while( left != (right-1) ){
        	if( isBadVersion( center ) ){
        		right = center;
        	}
        	else{
        		left = center;
        	}
        	center  = left + (right-left)/2;
        }
        return isBadVersion(left)?left:right;
    }
};

