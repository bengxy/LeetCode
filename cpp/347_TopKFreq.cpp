class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        for(int i=0;i<nums.size();i++){
        	record[nums[i]]++;
        }
        //priorit_queue<int, unordered_map<int, int>, comp> heap(record.begin(), record.end());
        vector<pair<int,int>> store(record.begin(), record.end());
        std::sort(store.begin(), store.end(), comp);
        std::vector<int> res;
        auto iter = store.begin();
        for(int i=0;i<k;i++){
        	res.push_back(iter->first);
        	iter++;
        }
        return res;
    }
    static bool comp(const pair<int, int>& a, const pair<int, int>& b){
    	return a.second > b.second;
    }
};