class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length())
            return "";
        map<char,int> need;
        map<char,int> m;
        int cnt = 0;
        for(int i=0;i<t.length();i++){
            if(need[t[i]]==0)
                cnt ++;
            need[t[i]] ++;
        }
        int l = 0;
        int r = 0;
        int result = s.length();
        string temp;
        int match = 0;
        while(r<s.length()){
            need[s[r]] -= 1;
            if(need[s[r]]>=0)
                match += 1;
            if(match==t.length()){
                while(l<=r&&need[s[l]]<0){
                    need[s[l]] += 1;
                    l ++;
                }
                if (result >= r-l+1){
                    result = r-l+1;
                    temp = s.substr(l,result);
                }
            }
            r++;
        }
        return temp;
    }
};
