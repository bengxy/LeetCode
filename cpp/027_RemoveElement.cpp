class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if( nums.empty() )
            return 0;
        int start = 0;
        int end = nums.size()-1;
        while( start < end){
            while( nums[end] == val)
                end--;
            if(end<0)
                return 0;
            if( nums[start] == val){
                nums[start] = nums[end];
                end--;
            }
            else
                start++;
        }
        if( nums[start] == val)
            start--;
        return start+1;
    }
};