class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	std::vector<std::vector<int>> res;

		nums.sort();
        //erase;
    

        if( nums.size() >= 3){
        	std::vector<int> tmp;
        	
        	int slow, quick;
        	int base = 0;
        	//int last = 0;
        	while( base < nums.size() - 2 ){
        		slow = base+1;
        		while( slow < nums.size() -1 ){
        			quick = slow+1;
        			while( quick<nums.size() ){
        				if( nums[base]+nums[slow]+nums[quick] == 0){
        					tmp.push_back(nums[base]);
        					tmp.push_back(nums[slow]);
        					tmp.push_back(nums[quick]);
        					quick = slow+2;
        				}
        				quick++;
        			}
        			slow++;
        		}
        		base++;
        	}



        }
        
        return res;
        
    }
};


-6 -4 -3 -1 0 2 2 5 6 10 100
-6 -4 -3 -1 0 2 2 5 6 10 100
-6 -4 -3 -1 0 2 2 5 6 10 100

2 1 2 1 2 0 3 1 4 90

-13 

