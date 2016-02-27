class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	std::vector<string> res;
    	string x = ["abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"];

    	if( digits.size() == 0){
    		return res;
    	}
    	res.push_back();
    	for( int i=1;i<digits.size();i++){
    		char c = digits.at(i);

    		int index = trans(c)-'2';
    		x[index]
    	}
        


    }

    string trans(char c){

    }
  
};