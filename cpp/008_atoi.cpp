class Solution {
public:
    int myAtoi(string str) {
    	s.erase(0,str.find_first_not_of(" "));  
    	s.erase(str.find_last_not_of(" ") + 1);  
    	if(str == ""){
    		return 0;
    	}

    	int flag = 1;
    	string targetStr = "2147483647";
    	if(str.at(0) == '-'){
    		flag = -1;
    		targetStr = "2147483648";
    		if(str.length()==1)
    			return 0;
    		else if(str.at(1) == '+')
    		    str = str.substr(2,str.length());
    		else 
    		    str = str.substr(1,str.length());
    	}
    	if(str.at(0) == '+'){
    		str = str.substr(1,str.length());
    	}

       	start = 0;
       	bool find = True;
        for(int i=0;i<str.length();i++){
        	if(find && str.at(i) == '0'){
        		start  = i+1;
        		continue;
        	}
        	find = False;
        	if( !isdigit(str.at(i)) )
        		return 0;
        }
        str = str.substr(start, str.length());
        if(str.length() > 10){
        	return 0;
        }
        if(str.length() == 10){
        	if (strcmp(str.c_str(), targetStr.c_str()) > 0){
        		str = targetStr;
        	}
        }
        int num = 0;
        for(int i=0;i<str.length();i++){
        	num = num*10 +int(str.at(i)-'0');
        }
        return num*flag;
    }
};