class Solution {
public:
    bool isMatch(string s, string p) {
        if(s=="")
        	return true;
        else if(p!="" && s!=""){
        	char c = p.at(0);
        	if( c==s.at(0) || c=='.')
        		return isMatch(s.substr(1), p.substr(1));
        	else if( c=='*'){
        		if(p.size() == 1) return true;
        		//找到p里面第一个字母位置i,并统计'.'的个数point
        		int point = 0;
        		int i;

        		for(i=0;i<p.size();i++){
        			char pv = p.at(i);
        			if( pv!='*' && pv!='.')
        				break;
        			else if( pv=='.')
        				point++;
        		}
        		//找到s中和它匹配的
        		for(int j=0;j<s.size();j++){
        			if(point>0){
        				//把p中的'.'消耗掉
        				continue;
        			}
        			if( s.at(j) == p.at(i))	{
        				if( isMatch(s.substr(j+1), p.substr(i+1)))
        					return true;
        			}
        		}
        		return false;
        	}
        	else
        		return isMatch(s.substr(0), p.substr(1));
        } 
        else
        	return false;
    }
};