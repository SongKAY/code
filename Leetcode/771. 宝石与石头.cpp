class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,int> m;
        for(int i=0;i<J.length();i++)
            m[J[i]] = 1;
        int cnt = 0;
        for(int i=0;i<S.length();i++){
            if(m[S[i]]==1)
                cnt++;
        }
        return cnt;
    }
};
