class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k<=0 || t<0 || nums.size() <2)
            return false;
        set<int> v;
        for(int i=0;i<nums.size();i++){
            if(i>k)
                v.erase(nums[i-k-1]); //sliding window
            
            //Let's find the lowest num bigger than num[i]-t : is the possible number
            // and if this number close to nums[i]+-t ; than it is!
            set<int>::iterator lower = v.lower_bound(nums[i]-t);    
           
            if(lower != v.end() && abs(nums[i] - *lower)<=t)
                return true;
            v.insert(nums[i]);
        }
        return false;
    }
};