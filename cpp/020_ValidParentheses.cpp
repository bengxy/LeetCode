class Solution{
public:
    bool isValid(string  s){
        if(s==""){
            return true;
        }
        stack<char> stk;
        stk.push(s.at(0));
        for(int i=1;i<s.size();i++){
            char c = s.at(i);
            if( c == '(' || c=='[' || c=='{')
                stk.push(c);
            else{
                if( !stk.empty()){
                    char x = stk.top();
                    if ((x== '(' && c==')')|| 
                        (x== '[' && c==']')||
                        (x== '{' && c=='}')){
                        stk.pop();
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        return stk.empty()?true:false;
    }
};