class Solution {
private:
	int N;
public:

	void dfs( vector<vector<string>>& res, vector<string>& possible, 
		int step){
		if( step == N)
			return res.push_back(possible);
		for( int i=0;i<N;i++){
			int level = step;
			bool error = false;
			while( --level >= 0){
				int upleft = i-step+level;
				int upright = i+step-level;
				if( (possible[level][i] == 'Q') ||
					((upleft>=0) && (possible[level][upleft]=='Q') ) ||
					((upright<N) && (possible[level][upright]=='Q') ) 
				){
					error = true;
					break;
				}
			}
			if(error)
				continue;
			possible[step][i] ='Q'; 
			dfs(res, possible, step+1);
			possible[step][i] = '.';

		}
	}
    vector<vector<string>> solveNQueens(int n) {
    	N = n;
    	vector<vector<string>> res;
    	vector<string> possible(n, string(n, '.'));
    	dfs(res, possible, 0);
    	return res;
    }
    
};