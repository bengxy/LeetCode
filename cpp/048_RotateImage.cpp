class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	int c = n/2;
    	for( int i=0;i<c;i++){
    		for(int j=0;j<n-1-i*2;j++){
    			int offset = i+j;
    			int tmp = matrix[offset][i];
    			matrix[offset][i] = matrix[n-i-1][offset];
    			matrix[n-i-1][offset] = matrix[n-offset-1][n-i-1];
    			matrix[n-offset-1][n-i-1] = matrix[i][n-offset-1];
    			matrix[i][n-offset-1] = tmp;
    		}
    	}
    }
};