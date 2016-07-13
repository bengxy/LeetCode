//不可取模
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
    	int big, small;
        x>y?(big=x,small=y):(big=y,small=x);
        if( z>(big+small) || z<0) return false;
        else if(z==0) return true;
        else if( small == 0 && z!=big) return false;
        else if( small == 1) return true;


        bool gys = false;
        int i;
        for(i=2;i<=x;i++){
        	if( big%i==0 && small%i==0){
        		gys = true;
        		break;
        	}
        }
        if(!gys){
        	return true;
        }
        return (big+small-z)%i==0;
    }
};