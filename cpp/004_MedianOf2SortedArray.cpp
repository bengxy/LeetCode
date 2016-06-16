// 这题可以扩展为 找到两个sorted list的第k大元素
// 中位数就是第 k = total/2 个数

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = n+m;
        if( total%2 == 1)
        	return median(nums1, m, 0, nums2, n, 0, total/2+1);
        else
        	return (median(nums1, m, 0, nums2, n, 0, total/2)+median(nums1, m, 0, nums2, n, 0, total/2+1))/2;

    }
    // 每次从两个串里面,切k/2个,把小的那部分扔掉,相应的k缩放
    double median(vector<int>& nums1, int m, int s1, vector<int>& nums2, int n, int s2, int k){
    	// Assure m is less than n
    	if(m>n)
    		return median(nums2, n, s2, nums1, m, s1, k);
    	// nums1 empty
    	if( m == 0)
    		return nums2[k-1];
    	// n+m <= 3
    	if( k == 1)
    		return min(nums1[s1] , nums2[s2]);

    	int a = min(k/2, m);
    	int b = k-a;
    	if( nums1[a+s1-1] <= nums2[b+s2-1]){
    		return median(nums1, m-a, s1+a, nums2, n, s2, k-a);
    	}
    	else{
    		return median(nums1, m, s1, nums2, n-b, s2+b, k-b);
    	}

    }
};