//也可以对A C G T bit到2' 00,01,10,11上
//这样 长度10的字符串需要20bit来表示一共是0xfffff+1种可能
//开一个 a=[0x100000]的数组
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        std::vector<string> res;
        if(s.size()<11)
        	return res;
        unordered_map<string,int> record;
        for( int i=0;i<=s.size()-10;i++){
        	string substr = s.substr(i, 10);
        	if( record.find(substr)!=record.end() ){
        		if (record[substr]==1){
        			res.push_back(substr);
        			record[substr]++;
        		}
        	}
        	else
        		record[substr] = 1;  	
        }
        return res;
    }
};