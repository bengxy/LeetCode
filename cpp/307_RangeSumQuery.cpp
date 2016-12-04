struct Node{
	int s,e,c, sum;
	Node* left;
	Node* right;
	Node(int a, int b):s(a),e(b),c((a+b)/2),sum(0),left(NULL),right(NULL){}
};

class NumArray {
private:
	Node* root;
	Node* build(vector<int>& nums, int start, int end){
		if(start>end) return NULL;
		Node* now = new Node(start, end);
		if(start == end){
			now->sum = nums[start];
			return now;
		}
		int c = start + (end - start) / 2;  //prevent overflow
		now->left = build(nums, start, c);
		now->right = build(nums, c+1, end);
		now->sum = now->left->sum + now->right->sum;
		return now;
	}
	int set(int i, int v, Node* now){
		if( now==NULL) return 0;
		int d;
		if(now->s == i && now->e ==i){
			d=v-now->sum;
			now->sum = v;
			return d;
		}
		if( i>now->c){
			d = set(i, v, now->right);
		}
		else{
			d = set(i, v, now->left);
		}
		now->sum +=d;
		return d;
	}
	int get(int i, int j, Node* now){
		if( now == NULL) return 0;
		if( now->s == i && now->e==j) return now->sum;
		if( i>now->c) return get(i, j, now->right);
		if( j<=now->c) return get(i, j, now->left);
		return get(i, now->c, now->left) + get(now->c+1, j, now->right);
	}
public:
    NumArray(vector<int> &nums) {
    	//int l = nums.size();
        //vector<vector<int> > cache = vector<int>(l, vector<int>(l, 0) ); 
        root = build(nums, 0, nums.size()-1);
    }

    void update(int i, int val) {
        set(i, val, root);
    }

    int sumRange(int i, int j) {
        return get(i, j, root);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);