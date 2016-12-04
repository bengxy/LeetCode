class NumMatrix {
private:
	vector<vector<int>> t;
public:
    NumMatrix(vector<vector<int>> &matrix) {
    	//this->matrix  = matrix;
    	if(matrix.empty() || matrix[0].empty()) return;
    	t.resize( matrix.size()+1, vector<int>(matrix[0].size()+1, 0) );
        for(int i=0;i<matrix.size();i++){
        	for(int j=0;j<matrix[0].size();j++){
        		t[i+1][j+1] = t[i][j+1]+t[i+1][j]-t[i][j] + matrix[i][j];
        	}
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
		return t[row2+1][col2+1] - t[row1][col2+1] - t[row2+1][col1] + t[row1][col1];
        //matrix[]
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);