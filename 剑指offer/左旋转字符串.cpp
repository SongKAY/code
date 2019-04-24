class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.length()==0)
            return str;
        int m = n % str.length(); 
        string s;
        s = str.substr(m,str.length()-m) + str.substr(0,m);
        return s;
    }
};
