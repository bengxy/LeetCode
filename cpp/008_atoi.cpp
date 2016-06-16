class Solution {
public:
    int myAtoi(string str) {
        int bound = INT_MAX/10;
        
        int res = 0;
        if(str.empty())
            return res;
        int i = 0;
        while(str.at(i) ==' ')
            i++;
        
        bool positive = true;
        if( str.at(i) == '-' ){
            positive  = false;
            i++;
        }
        else if(str.at(i) == '+')
            i++;
        
        while(i<str.size()){
            if(str.at(i)<'0'||str.at(i)>'9')
                break;
            if(res<=bound){
                res = res*10+(int)(str.at(i)-'0');
                if( res>=0 ){
                    i++;
                    continue;
                }
            }
            return positive?INT_MAX:INT_MIN;
            // else
            //     return positive?INT_MAX:INT_MIN;
            
        }
        return positive?res:-res;
    }
};