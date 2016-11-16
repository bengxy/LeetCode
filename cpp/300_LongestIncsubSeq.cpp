/*
Dynamic Programming:
O(N^2) Solution:
 for i to num :
 	calc the longest until i;
 	then
 	for x (x in 0~i-1):
 		if val[i] > val[x]
 			val[i] = val[x]+1 // because longest sub seq is update by +1
 //which take N*N

 O(NlogN) Solution:
 as we can record the longest seq in a vector longest<>
 
 first, we put the num[0] to longest[0]
 define last = the last position
 for i to num: (start from 1)
 	if i < longest[0]: // means this is smaller
 		// by change the first  the max length of subseq is not changed
 		// the max length is the size of longest(value of last);
 		longest[0] = i;
 	elif i> longest[last]: // means we can update the longest sub seq
 		//we push_back the val
		longest[++last] = i
 	else: 	// we need to do binary search 
 			// and change the num exactly bigger than i
 			// greedy!!!
 		pos = binary_search(i)
 		longest[pos] = i;


*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if(nums.empty()) return 0;
        vector<int> lis(nums.size());
        int last = 0;
        lis[0] = nums[0];
        for(int i=1;i<nums.size();i++){
        	if( nums[i] < lis[0])
        		lis[0] = nums[i];
        	else if( nums[i] > lis[last])
        		lis[++last] = nums[i];
        	else //we are sure : last > 0
        		lis[bs(lis, 0, last, nums[i])] = nums[i];
        }
        return last+1;
    }
    int bs(vector<int>& lis, int start, int end, int target){
    	//find exactly the smallest number bigger then target
    	while(start<=end){
    		int c = (start+end)/2;
	    	if( lis[c] == target) return c;
	    	// as we are sure : end> start
	    	//c+1 will not out of bound
	    	else if(lis[c]<target && lis[c+1]>target) return c+1;
	    	else if(lis[c]>target && lis[c+1]<target) return c;
	    	else if( lis[c]< target) start = c;
	    	else end = c;
    	}
    	return 0;	
    }

};