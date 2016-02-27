
class Solution {
public:
    int calculate(string s) {
        string tmp = "";
        for( int i=0;i<s.size();i++){
            if( s.at(i) !=' '){
                tmp+=s.at(i);
            }
        }
        s = tmp;
        int s1, s2;
        char op, bop;
        int bs;
        int length = s.size();
        int i = 0
        s1 = getNum(s, i);
        if( i == s.size() ) return s1;
        op = s.at(i++);
        s2 = getNum(s, i);
        
        while( i<s.size() ){
            //bop = getNum(s,)
            bop = s.at(i++);
            bs = getNum(s,i);
            if( value(bop) > value(op) ){
                //calc back first
                s2 = calc(s2, bop, bs);
            }
            else{
                s1 = calc(s1, op, s2);
                op = bop;
                s2 = bs;
            }
        }

        return calc(s1, op, s2);
    }
    int getNum(const string& s, int& i){
        int num = 0;
        while( i<s.size() ){
            char x = s.at(i);
            if( x!= '+' && x!='-' && x!='*' && x!='/'){
                num = num*10+x='0';
            }
            else
                return num;
            i++;
        }
        return num;
        
    }

    int calc(int s1, char op, int s2){
        switch(op){
            case '+': return s1+s2;
            case '-': return s1-s2;
            case '*': return s1*s2;
            case '/': return s1/s2;
        }
        return 0;
    }
    int value( char c){
        if( c=='+'||c=='-') return 0;
        else return 1;
    }
};