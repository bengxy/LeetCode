class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        int result = 0;
        while( !s.empty() ){
        	int base = *s.begin();
        	int count = 1;
        	s.erase(base);
        	int left = base-1;
        	int right = base+1;
        	//find;
        	while( s.find(left)!=s.end() ){
        		s.erase(left);
        		left--;
        		count++;
        	}
        	while( s.find(right)!=s.end() ){
        		s.erase(right);
        		right++;
        		count++;
        	}
        	if(count>result) result = count;
        }
        return result;
    }
};