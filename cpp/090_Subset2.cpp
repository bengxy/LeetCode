#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> subsetsWithDup(vector<int>& nums){
	vector<vector<int>> res;


}
void helper(vector<vector<int>>& res, vector<int>& nums, int idx){

	int l = res.size();
	int v = nums[idx];
	for( int i=0;i<l;i++){
		if(  (res[i].size()==0) && (res[i][0] == v) )
			continue;
		if( )
	}






}



/*

[1,2,2]
_
1
2
1 2
122
22
*/