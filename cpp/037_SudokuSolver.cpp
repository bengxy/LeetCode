class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> flag[3];
        fill(flag.begin(), flag.end(), unordered_set<char>(9));
        // init
        for( int i=0;i<9;i++){
        	for( int j=0;j<9;j++){
        		if(board[i][j] != '.'){
        			flag[0][i].insert(board[i][j]);
        			flag[1][j].insert(board[i][j]);
	        		flag[2][i/3+j/3*3].insert(board[i][j]);
        		}
        	}
        }
        // check
        return mark(board, flag, 0, 0);
    }
    bool mark(vector<vector<char>>& board, vector<unordered_set<char>>& flag, int i, int j){
    	if( j==9) 
    		return true;
    	int nexti = (i+1)%9;
    	int nextj = (i+1)/9+j;
    	if( board[i][j] != '.'){
    		return mark(board, flag, nexti, nextj)
    	}
    	for( int num=0;num<10;num++){
    		char target=(char)('0'+num);
    		int offset = i/3+j/3*3;
    		if( flag[0][i].find(target)==flag[0][i].end() &&
				flag[1][j].find(target)==flag[1][j].end() &&
        		flag[2][offset].find(target) == flag[2][offset].end() ){
        			board[i][j] = target;
        			flag[0][i].insert(target);
        			flag[1][j].insert(target);
        			flag[2][offset].insert(target);

        			if( mark(board, flag, nexti, nextj) )
        				return true;
        			else{
        				flag[0][i].erase(target);
        				flag[0][j].erase(target);
        				flag[0][offset].erase(target);
        			}
        				
			}
    	}
    	return false;
    } 
};