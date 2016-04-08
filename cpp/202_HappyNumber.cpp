class Solution {
public:
    bool isHappy(int n) {
    	//n is postive
        unordered_set<int> s;
        while( n!= 1){
        	if( s.find(n)  != s.end() ){
        		return false;
        	}
        	s.insert(n);
        	//int tmp = n;
        	int tmp = 0;
        	while( n!=0){
        		tmp = tmp + (n%10)*(n%10);
        		n /=10;
        	}
        	n = tmp;
        }
        return true;
    }
};