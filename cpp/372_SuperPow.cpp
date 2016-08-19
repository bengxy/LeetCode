class Solution {
public:
    int superPow(int a, vector<int>& b) {
    	if(a>1337)
    		a = a%1337;
    	if(a == 0)
    		return 0;
    	return rc(a, b, 0);

    }
    int rc(int a, std::vector<int>& b, int start){
    	if( start == b.size()-1 && b[start]<=2){
    		if(b[start]==0) return 1;
    		else if(b[start]==1) return a;
    		else return (a*a)%1337;
    	}
    	int high = 0;
    	for(int i=start;i<b.size();i++){
    		int num = high + b[i];
    		high = (num%2==1)?10:0;
    		b[i] = num/2;
    	}
    
    //	cout<<endl;
    	//	high = a;
    	if( b[start] == 0)
    		start++;
    	int res = rc(a, b, start);
    	res = (res*res)%1337;
    	if( high == 10)
    		res = (res*a)%1337;
    	//cout<<res<<endl;
    	return res;
    }

};