class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	int c = 1;
    	int l = digits.size()-1;
        for(int i=l;i>=0;i--){
        	int res = digits[i]+c;
        	digits[i] = res%10;
        	c = res/10;
        	if(c == 0)
        		break;
        }
        if(c==1)
        	digits.insert(digits.begin(), 1);
        return digits;
    }
};