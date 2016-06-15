class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> res;
        if(matrix.empty())
        	return res;
        int m = matrix.size();
        int n = matrix[0].size();

        int min = m<n?m:n;

        for(int re=0;re<min/2;re++){
        	int i=re;
        	int j=re;

        	for(i=re;i<n-1-re;i++){	
        		res.push_back(matrix[j][i]);	
        	}
        	for(j=re;j<m-1-re;j++){
        		res.push_back(matrix[j][i]);
        	}

	        	for(;i>re;i--){
	        		res.push_back(matrix[j][i]);
	        	}	

        		for(;j>re;j--){
        			res.push_back(matrix[j][i]);
        		}

        }

        if(min%2){
        	cout<<"suc"<<endl;
        	int re = min/2;
        	if( min==m ){
        		for(int j=re;j<n-re;j++){
        			res.push_back(matrix[re][j]);
        		}
        	}
        	else if(min==n){
        		for(int i=re;i<m-re;i++){
        			res.push_back(matrix[i][re]);
        		}
        	}

        }
        return res;
    }
};