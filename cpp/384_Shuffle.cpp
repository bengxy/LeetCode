#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
class Solution {
public:
	vector<int> origin;
	vector<int> op;
    Solution(vector<int> nums) {
        vector<int> origin = nums;
        vector<int> op = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
    	vector<int> res;
    	int l = this->op.size();
        while(l>0){
        	int r = rand()%l;
        	res.push_back(this->op[r]);
        	this->op.erase(this->op.begin()+r);
        	l = this->op.size();
        }
        this->op = res;
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
 int main(void){
 	std::vector<int> num  = {1,2,3};
 	Solution s(a);

 	return 0;
 } 