class Solution {
public:
    double myPow(double x, int n) {
        bool flag = false;
        long m = n;
        if( m < 0){
            m = -m;
            x = 1/x;
        }
        double res;
        if( m == 0) return 1;
        else if(m == 1) return x;
        else{
            res = myPow(x, m/2);
            res*=res;
            if( m%2 ){
                res *= x;
            }
        }
        return res;
    }
};