class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) 
            return res;
        sort(nums.begin(), nums.end());
        int last = 0;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && (nums[i]==nums[i-1]) )
                continue;
            for(int j=i+1;j<nums.size()-1;j++){
                if(j>i+1 && (nums[j]==nums[j-1]) )
                    continue;
                int target = -(nums[i]+nums[j]);
                
                int index = -1;
                if( target < nums[j+1] || target>nums[nums.size()-1] )
                    continue;
                else
                    index = bs(nums, j+1, nums.size()-1, target);

                if( index!=-1){
                    int tmp[] = {nums[i], nums[j], nums[index]};
                    vector<int> vec(tmp, tmp+3);
                    res.push_back(vec);
                }
            }
        }
        return res;
    }
    int bs(vector<int>& nums, int start, int end, int target){        
        while(start<=end){
            int center = (start+end)/2;
            if( target>nums[center]){
                start = center+1;
            }
            else if( target<nums[center]){
                end = center-1;
            }
            else
                return center;
        }
        return -1;
    }
};