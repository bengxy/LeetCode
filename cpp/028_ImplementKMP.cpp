class Solution {
public:
    int strStr(string haystack, string needle) {
        int nl = needle.size();
        if(nl == 0)
            return 0;
        int hl = haystack.size();
        if( hl<=nl)
            return haystack==needle?0:-1;
        vector<int> next(nl);
        //build next;
        next[0] = -1;
        int pos;
        for(int i=1;i<nl;i++){
            pos = next[i-1];
            while(needle[pos+1] != needle[i] && (pos>=0))
                pos = next[pos];
            if( needle[i] == needle[pos+1])
                next[i] = pos+1;
            else
                next[i] = -1;
       }
        //cmp
       int pos_mark;
       int hp = 0;
       int np = 0;
       while(hp<hl && np<nl ){
            if( haystack[hp] == needle[np]){
                hp++;
                np++;
            }
            else{
                if( np==0)
                    hp++;
                else
                    np = next[np-1]+1;
            }
       }
       if( np == nl ){
            return hp-np;
       }
       else{
        return -1;
       }
    }
};