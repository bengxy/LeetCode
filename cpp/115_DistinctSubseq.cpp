class Solution {
public:
    int numDistinct(string s, string t) {
        int row = t.size()+1;
        int col = s.size()+1;
        if(row==1||col==1){
        	return 0;
        }
        //if( row > s)
        	//return 0;
        vector<vector<int>> mark(row, vector<int>(col, 0));
        int r,c;
        //r = c = 0;
        for(int i=0;i<col;i++){
        	mark[0][i] = 1;
        }
		for(r=1;r<row;r++){
			for(c=r;c<col;c++){	
				if( s.at(c-1) == t.at(r-1)){
					mark[r][c] = mark[r][c-1]+mark[r-1][c-1];
				}
				else{
					mark[r][c] = mark[r][c-1];
				}
                n;
			}
		}     
		return mark[r-1][c-1];   
    }
};