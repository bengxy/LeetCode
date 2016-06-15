//in C++ string is sortable
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	unordered_map<string, vector<string>> cont;
    	for(auto s:strs){
    		string tmp = s;
    		sort(tmp.begin(), tmp.end());
    		cont[tmp].push_back(s);
    	}
    	vector<std::vector<string> res;
    	for(auto iter:cont){
    		res.push_back(*iter.second);
    	}
    	return res;
        
    }
};