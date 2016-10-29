class Solution {
public:
	bool isAdditiveNumber(string num) {

       	int l = num.size();
       	//i, j the length of adder1, adder2
       	for(int i=1;i<=l/2;i++){
       		for(int j=1;j<=(l-i)/2;j++){
       			if(  helper(num, 0, i, j) )
       				return true;
       		}
       	} 
       	return false;
	}
	bool helper(string& num, int start, int adder1, int adder2){
		int sum_pos = start+adder1+adder2;
		if(sum_pos == num.size() ){
			if( start == 0)
				return false;
			else
				return true;
		}
		if( (num[start] =='0' && adder1>1) || (num[start+adder1] =='0' &&adder2>1)) 
			return false;
		long a1 = atol(num.substr(start, adder1).c_str());
		long a2 = atol(num.substr(start+adder1, adder2).c_str());
		if( a1 > INT_MAX || a2>INT_MAX)
			return false;
		int min_len = max(adder1, adder2);
		for( int i=min_len;i<=num.size()-start;i++){
			if( i>1 && num[sum_pos] == '0')
				return false;
			long sum = atol(num.substr(sum_pos, i).c_str());
			if(sum> (a1+a2) )
				return false;
			else if(sum == (a1+a2)  && helper(num, start+adder1, adder2, i))
				return true;
		}
		return false;
	}
};