class Solution {
public:
    int getValue(char s){
        switch(s){
            case('I'): return 1;
            case('V'): return 5;
            case('X'): return 10;
            case('L'): return 50;
            case('C'): return 100;
            case('D'): return 500;
            case('M'): return 1000;
            default: return 1/0;
            break;
        }
       
    }

    int romanToInt(string s) {
        int cur = 0;
        int prev = 0;
        int total = 0;
        for(int i = s.size()-1; i>=0; i--){
            cur = getValue(s.at(i));

            if(cur < prev){
                total = total - cur;
            }
            else{
                total = total + cur;
            }
            prev = cur;
        }
        
        return total;
    }
};