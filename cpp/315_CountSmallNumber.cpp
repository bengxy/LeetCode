
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        //std::sort(nums.begin(), nums.end());
        vector<int> res;
        if(nums.empty()){
        	return res;
        }
        else if( nums.size() == 1){
        	res.push_back(0);
        	return res;
        }
        vector<int> y(nums.size());
        int n = 0;
        std::generate(y.begin(), y.end(), [&]{return n++;});
        std::sort(y.begin(), y.end(), [&](int i1, int i2){ return nums[i1]!=nums[i2]?nums[i1]<nums[i2]:i1<i2;} );
        //get sorted index y;
        //priority_queue<int> maker;
        //using vector? binary insert
        
        res.push_back(y[0]);
        nums[y[0]] = 0;
        //int length = 0;
        for(int i = 1;i<y.size();i++){
        	//binary insert and return the index;
        	//big -- 2 -- small
        	if( y[i] > res[0]){
        		res.insert(res.begin(), y[i]);
        		nums[y[i]] = 0;
        		continue;
        	}
        	if( y[i] < res[res.size()-1]){
        		res.push_back(y[i]);
        		nums[y[i]] = res.size();
        		continue;
        	}
			int left = 0;
        	int right = res.size()-1;
        	int center = (left+right)/2;
        	cout<<"initial: "<<left<<" "<<right<<" "<<center<<endl;
        	int count = 0;
        	while(true){
        		if(right-left == 1){
        			res.insert(res.begin()+right, y[i]);
        			nums[y[i]] = right;
        			break;
        		}

        		if( y[i] < res[center]){
        			left = center;
        		}
        		//no equal!
        		else{
        			right = center;
        		}
        		cout<<"LOOP: "<<left<<" "<<right<<" "<<center<<endl;
        		center = (left+right)/2;
        		if(count++ == 10){
        		    break;
        		}
        	}
        }
        return res;
    }
};
