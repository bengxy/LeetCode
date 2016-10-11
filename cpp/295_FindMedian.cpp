class MedianFinder {
private:
	priority_queue<int> left;
	priority_queue<int, vector<int>, std::greater<int>> right;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        int ls = left.size();
        int rs = right.size();
        if( left.empty()){
        	left.push(num);
        	return ;
        }
        if( ls > rs){
        	if( num >= left.top())
        		right.push(num);
        	else{
        		right.push(left.top());
        		left.pop();
        		left.push(num);
        	}
        }
        else{
        	if( num<=right.top())
        		left.push(num);
        	else{
        		left.push(right.top());
        		right.pop();
        		right.push(num);
        	}
        }

    }

    // Returns the median of current data stream
    double findMedian() {
    	if(left.empty())
    		return 0;
        if( left.size() == right.size()){
        	return (double)(left.top()+right.top())/2;
        }
        else
        	return left.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();