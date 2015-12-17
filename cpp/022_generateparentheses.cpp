class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        
        
        for(int i=n;i>0;i--){
            string rawStr = "";
            int stackNum = n-i;
            for( int j=0;j<i;j++)
            	rawStr += "(";
            
        }
    }
};