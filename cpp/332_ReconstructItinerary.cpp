class Solution {
public:
	unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> G;
	vector<string> res;
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto iter:tickets){
        	G[iter.first].push(iter.second);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
    void dfs(string airport){
    	auto& neighbors = G[airport];
    	while(!neighbors.empty()){
    		string tmp = neighbors.top();
    		neighbors.pop();
    		dfs(tmp);
    	}
    	res.push_back(airport);
    }
};