class Solution {
public:
    int strStr(string haystack, string needle) {
    	int hsize = haystack.size();
    	int nsize = needle.size();
    	if(nsize==0)
    		return 0;
        if(nsize>hsize)
        	return -1;

        vector<int> buf(nsize);
        int i=1;
        int last=0;
        while(i<nsize){
        	if(needle[i]==needle[last]){
        		buf[i] = buf[last]+1;
        		last++;
        		i++;
        	}
        	else{
        		i++;
        		last = 
        	}

        }
    }
};