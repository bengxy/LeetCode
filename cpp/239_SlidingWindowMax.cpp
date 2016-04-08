// 贪心 
// trick ： 之后的每个数字  只需要和自己位置当前的max值比较，
//	如果当前的大，只需要跳到后面的k处 写
// 如果小，前后填满
// best case: O(N)  worst case (acs order) : O(Nk)


//Update: 
//Two pointer: 
// post=wait when  pre find between [pre and k*2-1 ]
// if bigger post fill all and post = pre  then pre++ >go
// if no bigger one , fill all post = 2*k

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if( nums.empty() ) return res;

        int post, pre;
        post = pre = 0;

        while( pre < nums.size()){
        //	bool findbigger = false;
        	while( pre < (post+k)  && pre < nums.size() ){
        		if( nums[pre] > nums[post]){
        			//findbigger = true;
        			//fill
        			pre = post;
        			break;
        		}
        		pre++;
        	}

        }
    }
};