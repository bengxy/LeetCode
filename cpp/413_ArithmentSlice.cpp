class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int i=1;
        int l = A.size();
        int res = 0;
        while(i<l){
        	int j = i+1;
        	int gap = A[i]-A[i-1];
        	while(j<l){
        		if(A[j]-A[j-1] == gap)
        			j++;
        		else
        			break;
        	}
        	res += (j-i)*(j-i-1)/2;
        	i = j;
        }
        return res;
    }
};