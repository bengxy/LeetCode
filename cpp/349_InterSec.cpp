class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.empty() || nums2.empty())
        	return res;
        unordered_set<int> x(nums1.begin(), nums1.end());
        
        for(int i:nums2){
        	if(x.find(i)!= x.end()){
        		res.push_back(i);
        		x.erase(i);
        	}
        }
        return res;
    }
};