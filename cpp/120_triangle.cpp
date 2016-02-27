class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> res;
        vector<int> tmp;
        tmp.push_back(triangle[0][0]);
        res.push_back(tmp);
        tmp.clear();
        for( int i=1;i<triangle.size();i++){
        	vector<int> tmp;
        	tmp.push_back(triangle[i][0]+res[i-1][0]);
        	for( int j=1;j<triangle[i].size()-1;j++){
        		//int val = || 
        		int lhs = res[i-1][j-1]+triangle[i][j];
        		int rhs = res[i-1][j]+triangle[i][j];
        		//int val = lhs
        		tmp.push_back( (lhs<rhs)?lhs:rhs );
        	}
        	//vector<int> tmp;
        	tmp.push_back(triangle[i][triangle[i].size()-1] + res[i-1][triangle[i-1].size()-1]);
        	res.push_back(tmp);
        }
        int i = res.size()-1;
        int min = res[i][0];
        for(int j=1;j<res[i].size();j++){
        	if( res[i][j]<min)
        		min = res[i][j];
        }
        return min;
    }
};