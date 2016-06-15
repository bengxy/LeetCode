class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    	int n = board.size();
    	if( n == 0) return ;
    	int m = board[0].size();
    	if( m== 0) return ;
    	int X_offset[8] = {-1,0,1,-1,1,-1,0,1};
    	int Y_offset[8] = {-1,-1,-1,0,0,1,1,1};
        for( int i=0;i<n;i++){
        	for( int j=0;j<m;j++){
        		//check alive of 8 neighbers;
        		int sum = 0;
        		for(int k=0;k<8;k++){
        			int new_i = i+X_offset[k];
        			int new_j = j+Y_offset[k];
        			if( new_i>=0&&new_i<n && new_j>=0&&new_j<m)
        				sum = sum+(board[i+X_offset[k]][j+Y_offset[k]] & 0x1);
        			
        		}
        		
        		if( board[i][j] == 1){
        			if( sum <2 || sum>3)
        				board[i][j] = 1;
        			else
        				board[i][j] = 3;
        		}
        		else{
        			if( sum==3)
        				board[i][j] = 2;
        		}
        	}
        }
        for( int i=0;i<n;i++){
       		for( int j=0;j<m;j++){
       			board[i][j] = board[i][j]>>1;
       		}
       	}
    }
};