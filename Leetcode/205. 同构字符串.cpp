class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        int n = s.length();
        map<char,char> m;
        map<char,int> flag;
        for(int i=0;i<n;i++)
            flag[t[i]] = 0;
        for(int i=0;i<n;i++){
            if(m.find(s[i])==m.end()){
                if(flag[t[i]])
                    return false;
                m[s[i]] = t[i];
                flag[t[i]] = 1;
            }
            else{
                if(m[s[i]]!=t[i])
                    return false;
            }
        }
        return true;
    }
};
