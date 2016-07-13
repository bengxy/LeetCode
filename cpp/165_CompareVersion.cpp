class Solution {
public:
    int compareVersion(string version1, string version2) {
        int s1,s2;
        s1 = s2 = 0;
        while(s1<version1.size()&&s2<version2.size()){
        	int end1 = version1.find_first_of('.', s1);
        	int end2 = version2.find_first_of('.', s2);	
        	cout<<end1<<end2<<endl;
        	string sub1 = version1.substr(s1, end1);
        	string sub2 = version2.substr(s2, end2);
        	cout<<sub1<<endl;
        	cout<<sub2<<endl;
        	//cmp
        	if(sub1.size()!=sub2.size()){
        		return sub1.size()>sub2.size()?1:-1;
        	}
        	else{
        		if(sub1!=sub2){
        			return strcmp(sub1.c_str(), sub2.c_str());
        		}
        		else{
        			s1 = end1;
        			s2 = end2;
        		}
        	}
        }
        if(s1>=version1.size() &&s2>=version2.size()){
        	return 0;
        }
        else{
        	return s1>=version1.size()?1:-1;
        }
        
    }
};