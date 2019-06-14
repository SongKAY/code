class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tlen = 0;
        for(int i=0;i<t.length();i++){
            if(t[i]==s[tlen]){
                tlen++;
            }
        }
        if(tlen==s.length())
            return true;
        return false;
    }
};
