class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0;
        int rf = 0;
        int n = A.size();
        for(int i=0;i<n;i++){
        	sum+=A[i];
        	rf += i*A[i];
        }
        int max = rf;
        for(int i=n-1;i>0;i--){
        	rf = rf - n*A[i] + sum;
        	if( rf>max)
        		max = rf;
        }
        return max;
    }
};