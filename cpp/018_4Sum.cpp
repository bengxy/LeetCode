class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> res;
        int l = nums.size();
        if( l< 4)
            return res;
        std::sort(nums.begin(), nums.end());
        for(int i=0;i<l-3;i++){
            if( i>0 && nums[i] == nums[i-1])
                continue;
            for(int j=i+1;j<l-2;j++){
                if( j>i+1 && nums[j] == nums[j-1])
                    continue;
                int low = j+1;
                int high = l-1;
                int t = nums[i] + nums[j] - target;
                while(low < high){
                    if(( nums[low]+nums[high] + t) > 0)
                        high--;
                    else if( (nums[low]+nums[high] + t )< 0)
                        low++;
                    else{
                        res.push_back(vector<int> {nums[i], nums[j], nums[low], nums[high]});
                        int small = nums[low];
                        int big = nums[high];
                        while(low< l && nums[low] ==small)
                            low++;
                        
                        while(high>=0&&nums[high] == big)
                            high--;
                        //vector<int> tmp(nums[i], nums[j], nusm[])
                    }
                }

            }
        }
        return res;
    }
};