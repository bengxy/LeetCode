class Solution {
private:
	vector<pair<int, int>> res;
	int ocean[150][150];
	void dfs(vector<vector<int>>& matrix, int x, int y, int pre, int mask){
		//cout<<x<<" "<<y<<endl;
		if( x<0 || x>= matrix.size() || y<0 || y>= matrix[0].size() ||
			matrix[x][y] < pre || ((ocean[x][y] & mask ) ==mask) ){
			//avoid:  over bound || can't pass || have passed
			return ;
		}
		//cout<<" passed"<<endl;
		ocean[x][y] |= mask;
		if( ocean[x][y] == 3)
			res.push_back({x,y});
		dfs(matrix, x-1, y, matrix[x][y], ocean[x][y]);
		dfs(matrix, x+1, y, matrix[x][y], ocean[x][y]);
		dfs(matrix, x, y-1, matrix[x][y], ocean[x][y]);
		dfs(matrix, x, y+1, matrix[x][y], ocean[x][y]);
	}
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {

       	if( matrix.empty())
       		return res;
       	int m = matrix.size();
       	int n = matrix[0].size();
       	//cout<<"NNN"<<n<<endl;
       	//cout<<"a"<<endl;
       	memset(ocean, 0, sizeof(ocean));
       	 //     cout<<"b"<<endl;
       	for(int i=0;i<m;i++){
       	//	cout<<"c"<<endl;
       		dfs(matrix, i, 0, INT_MIN, 1);
       		dfs(matrix, i, n-1, INT_MIN, 2 );
       	}
       	//cout<<"abc"<<endl;
       	for(int j=0;j<n;j++){
       	//	cout<<"d"<<endl;
       		dfs(matrix, 0, j, INT_MIN, 1);
       		dfs(matrix, m-1, j, INT_MIN, 2 );
       	}
       	return res;
    	}
};