class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector< pair<int, int> > toSort;
        for( int i=0;i<nums.size();i++){
        	toSort.push_back(pair<int,int>(nums[i], i));
        }
        std::sort(toSort.begin(), toSort.end(), cmp);
        for( int i=0;i<nums.size();i++){
        	int j = i+1;
        	//while( )
        	while( j< nums.size() ){
        		if( toSort[j].first - toSort[i].first > t)
        			break;
        		else
        	}
        }
    }
    bool cmp{

    }
};