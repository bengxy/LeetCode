class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
        	return ;
        int M = matrix.size();
        int N = matrix[0].size();
        bool row = false;
        bool col = false;
        for(int i=0;i<M;i++)
        	if(matrix[i][0] == 0){
        		row = true;
        		break;
        	}
        for(int j=0;j<N;j++){
        	if(matrix[0][j] == 0){
        		col = true;
        		break;
        	}
        }	
        for(int i=1;i<M;i++){
        	for(int j=1;j<N;j++){
        		if(matrix[i][j] == 0){
        			matrix[i][0] = 0;
        			matrix[0][j] = 0;
        		}
        	}
        }
        for(int i=1;i<M;i++){
        	for(int j=1;j<N;j++){
        		if((matrix[i][0] == 0) || (matrix[0][j] == 0))
        			matrix[i][j] = 0;
        	}
        }
        if(row){
        	for(int i=0;i<M;i++){
        		matrix[i][0] = 0;
        	}	
        }
        if(col){
        	for(int j=0;j<N;j++){
        		matrix[0][j] = 0;
        	}
        }
    }
};