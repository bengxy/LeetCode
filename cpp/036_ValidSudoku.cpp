class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool table[27][9];
        memset(table, false, 27*9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.')
                    continue;
                int val = board[i][j]-'1';
                if(table[i][val] || table[9+j][val] ||table[18+i/3+j/3*3][val])
                    return false;
                else{
                    table[i][val]=true;
                    table[9+j][val]=true;
                   
                    table[18+i/3+j/3*3][val]=true;
                }
            }
        }
        return true;
    }
};
