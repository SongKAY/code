class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
            return 0;
        int maxlen = 0;
        map<char,int> m;
        int l = 0;
        int r = 0;
        while(r<s.length()){
            if(m[s[r]]==0){
                maxlen = max(maxlen,r-l+1);
                m[s[r]] = 1;
                r++;
            }
            else{
                while(l<r&&m[s[r]]){
                    m[s[l]] = 0;
                    l++;
                }
                maxlen = max(maxlen,r-l+1);
                m[s[r]] = 1;
                r++;
            }
        }
        return maxlen;
    }
};
