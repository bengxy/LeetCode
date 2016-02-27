class Solution {
public:
    int numTrees(int n) {
        if( n<=1)
            return 1;
        vector<int> index(n+1, 0);
        index[0] = 1;
        for( int i=1;i<=n;i++){
            int center = i/2;
            for(int j=0;j<center;j++){
                index[i] =index[i] + index[j]*index[i-1-j];
            }
            index[i] =index[i] * 2;
            if( i%2!=0 ){
                index[i] =index[i] + index[center]*index[center];
            }
        }
 
        return index[n];
    }
};