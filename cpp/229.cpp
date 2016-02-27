class Solution{
public:
	vector<int> majorityElement(vector<int>& nums){
		int m1, m2;
		int l1, l2;
		std::vector<int> res;
		if(nums.size() < 3 ){
			return nums;
		}
		m1 = nums[0];
		l1 = 1;
		int i = 0;
		while( ++i< nums.size() ){
			if( nums[i] == m1)
				l1++;
			else
				break;
		}
		if( i==nums.size()){
			res.push_back(m1);
			return res;
		}
		m2 = nums[i];
		l2 = 1;
		while(++i<nums.size()){
			if( nums[i] != m1 && nums[i] != m2){
				//l1--; l2--;
				//if()
			}
			else if( nums[i] == m1){
				l1++;
			}
			else{
				l2++;
			}
		}
	}
};


