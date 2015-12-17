class Solution {
public:
	int uolhs, uorhs;
    int search(vector<int>& nums, int target) {
    	return unorder(nums, target, 0, nums.size()-1);
    }
 	int bst(const vector<int>& v, int target, int left, int right){
 		if(left == right)
 			return (v[left] != target)?-1:left;
 		int center = (left+right)/2;
 		int res = bst(v, target, left, center);
 		if(res == -1){
 			return bst(v, target, center+1, right);
 		}
 		else{
 			return res;
 		}
 	}
 	int unorder(const vector<int>& v, int target, int left, int right){
 		int center = （left+right)/2;
		if( v[left] < v[center]){	//左边有序
			if(v[left] <= target && v[center]>=target)
				return bst(v, target, left, center);
			else
				return unorder(v, target, center+1, right);
		}
		else{
			if(v[center+1] <= target && v[right] >= target)
				return bst(v,target, left,center);
			else
				return unorder(v, target, left, center);
		}
 	}
};