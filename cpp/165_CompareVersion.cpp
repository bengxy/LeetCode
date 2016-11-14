class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1, p2;
        p1 = p2 = 0;
        int l1 = version1.size();
        int l2 = version2.size();

        while(p1<l1 || p2<l2){
            int a = p1<l1?get_subversion(version1, p1):0;
            int b = p2<l2?get_subversion(version2, p2):0;
            if(a<b) return -1;
            if(b<a) return 1;
        }
        return 0;
    }
    int get_subversion(const string& s, int& start){
        int num = 0;
        while( start < s.size() && s[start]!='.')
            num =  num*10 + s[start++]-'0';
        start++;
        return num;
    }
};







class Solution {
public:
    int compareVersion(string version1, string version2) {
        int s1,s2;
        s1 = s2 = 0;
        while(s1<version1.size()&&s2<version2.size()){
        	int end1 = version1.find_first_of('.', s1);
        	int end2 = version2.find_first_of('.', s2);	
        	//cout<<end1<<end2<<endl;
        	string sub1 = version1.substr(s1, end1);
        	string sub2 = version2.substr(s2, end2);
        	//cout<<sub1<<endl;
        	//cout<<sub2<<endl;
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