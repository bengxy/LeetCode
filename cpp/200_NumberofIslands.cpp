class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	if(grid.empty())
    		return 0;
        int n = 0;
        for(int i=0;i<grid.size();i++){
        	for(int j=0;j<grid[0].size();j++){
        		if(grid[i][j]=='1'){
        			n++;
        			mark(grid, i, j)
        		}
        	}
        }
        return n;
    }
    void mark(vector<vector<char>>& grid, int i, int j){
    	//up down right left
    	if(i<0||i>=grid.size() || j<0 || j>=grid[0].size())
    		return ;
    	if(grid[i][j] == '1'){
    		grid[i][j] = '2';
    		mark(grid, i+1, j);
    		mark(grid, i-1, j);
    		mark(grid, i, j-1);
    		mark(grid, i, j+1);
    	}
    }
};