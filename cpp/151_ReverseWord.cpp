class Solution {
public:
    void reverseWords(string &s) {
        // remove space
        int slow, fast;
        slow = fast = 0;
        bool parse_word = true;
        bool read = false;
        while(fast<s.size()){
            if( s[fast] == ' '){
                if(read) parse_word = false;
                fast++;
            }
            else{
                if(parse_word){
                    s[slow] = s[fast];
                    read  = true;;
                }
                else{
                    s[slow++] = ' ';
                    s[slow] = s[fast];
                    parse_word = true;
                }
                slow++;
                fast++;
            }
        }
        //cout<<s<<'-'<<endl;
        s.erase(slow, fast-slow);
       // cout<<s<<'-'<<endl;
        // reverse all
        reverse(s.begin(), s.end());
        //cout<<s<<'-'<<endl;

        //reverse part
        auto start = s.begin();
        auto end = start+1;
        while(end <= s.end() ){
            if(end == s.end() || *end == ' '){
                reverse(start, end);
                start = end+1;
                end = start+1;
            }
            else{
                end++;
            }
        }
    //cout<<s<<'-'<<endl;

    }
};