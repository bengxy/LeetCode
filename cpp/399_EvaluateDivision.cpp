class Solution {
public:
	typedef struct _edge{
		string target;
		double value;
		Edge* next;
	}Edge;
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map< string, Edge* > link;
        vector<double> res;

		for (int i=0;i<values.size() ;i++){
			
			string lhs = equations[i].first;
			string rhs = equations[i].second;
			//neighbor[equations[i].second].
			link[lhs] = 
			link[rhs] = 

		}

    }
    double dfs(string src, string dst){

    }
};