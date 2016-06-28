class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    	if(numCourses>prerequisites.size()+1)
    		return false;
        bool flag[numCourses];
        memset(flag, false, sizeof(bool)*numCourses);

        for(int i=0;i<numCourses;i++){
        	
        }
    }
};