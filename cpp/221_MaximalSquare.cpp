class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	cout<<"go"<<endl;
    	int rows = matrix.size();
    	if(rows==0)
    		return 0;
    	int cols = matrix[0].size();
    	if(cols==0)
    		return 0;
    	//cout<<"#"<<endl;
    	vector<int> tmp(cols, 0);
    	vector<vector<int>> mask(rows, tmp);
    	int max_window = 0;
    	for(int i=0;i<rows;i++){
    		mask[i][0] = matrix[i][0]-'0';
    		if(mask[i][0]>max_window)
    			max_window=mask[i][0];
    	}
    	for(int j=0;j<cols;j++){
    		mask[0][j] = matrix[0][j]-'0';
    		if(mask[0][j]>max_window)
    			max_window=mask[0][j];
    	}
    	//cout<<"##"<<endl;
    	for(int i=1;i<rows;i++){
    		for(int j=1;j<cols;j++){
    			if(matrix[i][j]=='1'){
    				mask[i][j] = 1+min(mask[i-1][j-1], mask[i-1][j], mask[i][j-1]);
    			}
    			if(mask[i][j]>max_window)
    				max_window=mask[i][j];
    		}
    	}
    	return max_window*max_window;
    }
    int min(int a, int b, int c){
    	a = a<b?a:b;
    	a = a<c?a:c;
    	return a;
    }
};