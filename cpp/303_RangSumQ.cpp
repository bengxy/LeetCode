class NumArray {
private:
	vector<int> record;
	int size;
public:
    NumArray(vector<int> &nums) {
    	record.push_back(0);
    	int last = 0;
        for(int i:nums){
        	last = last + i;
        	record.push_back(last);
        }
        size = record.size();
    }

    int sumRange(int i, int j) {
       // if(i>=size || j>=size || i>j) return 0; //exception
        return record[j+1] -record[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);