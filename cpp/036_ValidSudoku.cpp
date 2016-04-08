class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for( auto i:board){
        	char a[9];
        	memset( a, 0, 9);
        	for( auto j: i){
        		if( j!='.'){
        			if( a[j-'0'] == 1)
        				return false;
        			else
        				a[j-'0'] = 1;
        		}
        	}
        }
        return true;
    }
};