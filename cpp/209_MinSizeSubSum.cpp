class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int slow, fast;
        slow = fast = 0;

        int gap  = INT_MAX;
        int sum = 0;
        while( fast < nums.size() || (slow < fast) ){
        	if( sum >= s){
        		//cout<<slow<<" "<<fast<<endl;
        		int tmp = fast-slow;
        		if( slow<fast){
        			gap = tmp<gap?tmp:gap;
        			sum -= nums[slow++];
        		}
        		else
        			return 1;
        	}
        	else if( fast >= nums.size())
        		break;
        	else{
        		sum += nums[fast++];
        	}
        }
        return (gap==INT_MAX)?0:gap;
    }
};