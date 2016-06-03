class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if( strs.empty() ) return "";
        if(strs[0]=="") return "";
        int cnt, j;
        bool goon = true;
        for( cnt= 0;cnt<strs[0].size();cnt++){
            for(j=1;j<strs.size();j++){
                if( strs[j].size()==cnt || strs[0].at(cnt) != strs[j].at(cnt) ){
                    goon = false;
                    break;
                }
            }
            if(!goon)
                break;
        }
        
        return strs[0].substr(0, cnt);

    }
};