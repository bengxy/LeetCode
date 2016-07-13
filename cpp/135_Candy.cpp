class Solution {
public:
    int candy(vector<int>& ratings) {
        int peak = 0;
        int peak_candy = 0;
        int sum = 1;
        int candy = 1;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i] == ratings[i-1]){
                peak = i;
                sum+=1;
                peak_candy = candy = 1;
            }
            else if( ratings[i] > ratings[i-1]){
                peak = i;
                candy++;
                sum += candy;
                peak_candy = candy;
            }
            else{
                candy = 1;
                sum +=(i-peak)<peak_candy?i-peak:i-peak+1;
            }
        }
        return sum;
    }
};