class Solution {
public:
    int numSquares(int n) {
        vector<int> rec {0};
        //cout<<"start "<<endl;
        int l = 1;
		while(l<=n){
			//cout<<"length "<<l<<endl;
			int min_value = INT_MAX;
			for(int i=1, sq;(sq=i*i)<=l;i++)
				min_value = std::min(1 + rec[l-sq], min_value);
			//cout<<"value "<<min_value<<endl;
			rec.push_back(min_value);
			l = rec.size();
		}
		l = rec[n];
		//cout<<endl;
		return l;
    }
};