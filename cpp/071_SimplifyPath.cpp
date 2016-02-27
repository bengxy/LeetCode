class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ps;
        path+='/';
        int n = path.size();
        string buff = "";
        for(int i=0;i<n;i++){
        	char c = path.at(i);
        	if( c == '/' ){
        		if(buff==""){
        			continue;
        		}
       			if(buff == ".."){
       				if( !ps.empty() ){
       					ps.pop();
       				}
       			}
       			else{
       				if( buff!="."){
       					ps.push(buff);	
       				
       				}
       			}
       			buff = "";
        	}
        	else{
        		buff+=c;
        	}
        }
        
        string res="";
        while( !ps.empty()){
        	res.insert(0, ps.top());
        	res.insert(0,"/");
        	ps.pop();
        }
        if( res==""){
            res+='/';
        }
        return res;
    }
};