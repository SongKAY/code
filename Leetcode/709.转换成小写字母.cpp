class Solution {
public:
    string toLowerCase(string str) {
        string s = str;
        for(int i=0;i<s.length();i++){
            if(s[i]>='A'&&s[i]<='Z')
                s[i] += 32;
        }
        return s;
    }
};
