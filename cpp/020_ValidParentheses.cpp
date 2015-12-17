class Solution {
public:
    bool isValid(string s){
    	if( s == ""){
    		return true;
    	}
        stack<char> stk;
        stk.push(s.at(0));
        for(int i=1;i<s.length();i++){

        	if( !stk.empty() && s.at(i) == stk.top()){
        		stk.pop();
        	}
        	else
        		stk.push(s.at(i));
        }
        return stk.empty()?true:false;
    }
};