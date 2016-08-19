class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        if( dungeon.empty() )
        	return 1;
        int M = dungeon.size();
        int N = dungeon[0].size();

        for(int i=M-1;i>=0;i--){
        	for(int j=N-1;j>=0;j--){
        		if( (i== M-1) && (j==N-1)){
        			dungeon[i][j] = dungeon[i][j]>0?0:dungeon[i][j];
        		}
        		else if( i == M-1){
        			int tmp = dungeon[i][j+1]+dungeon[i][j];
        			//dungeon[i][j] = 0;
        			dungeon[i][j] = tmp>0?0:tmp;
        		}
        		else if(j == N-1){
        			int tmp = dungeon[i+1][j]+dungeon[i][j];
        			dungeon[i][j] = tmp>0?0:tmp;
        		}
        		else{
        			int tmp = max(dungeon[i][j+1], dungeon[i+1][j])+dungeon[i][j];
        			dungeon[i][j] = tmp>0?0:tmp;
        		}
        	}
        }
        return 1-dungeon[0][0];
    }
};