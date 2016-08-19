//topological sort
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {       
        vector<int> res;
        	
        bool flag[numCourses];
        memset(flag, false, sizeof(bool)*numCourses);
        vector<vector<int>> mask(numCourses);
        for(int i=0;i<prerequisites.size();i++){
        	mask[prerequisites[i].second].push_back(prerequisites[i].first);
        	flag[prerequisites[i].first] = true;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
        	if(!flag[i]){
        		q.push(i);
        		//flag[i] = true;
        	}
        }
        while(!q.empty()){
        	int number = q.front();
        	q.pop();
        	res.push_back(number);
        	for(auto i:mask[number]){
				if(flag[i]){
        			q.push(i);
        			flag[i] = false;
        		}
        	}
        }
        return res;
    }
};