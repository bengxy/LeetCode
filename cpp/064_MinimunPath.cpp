class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	if(grid.empty())
    		return 0;
    	int M = grid.size();
    	int N = grid[0].size();

        for(int i=0;i<M;i++){
        	for(int j=0;j<N;j++){
        		if(i==0 && j==0){
        			continue;
        		}
        		else if(i==0){
        			grid[0][j] += grid[0][j-1];
        		}
        		else if(j==0){
        			grid[i][0] += grid[i-1][0];
        		}
        		else{
        			grid[i][j] += std::min(grid[i-1][j], grid[i][j-1]);
        		}
        	}
        }
        return grid[M-1][N-1];
    }
};