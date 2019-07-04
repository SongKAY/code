class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int m = 0;
        int n = 0;
        for(auto s:S){
            m += int(s-'0');
            n = min(m,n+1-int(s-'0'));
        }
        return n;
    }
};
