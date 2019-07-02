class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int cnt = 0;
        if(K>S.length())
            return cnt;
        map<char,int> m;
        int num = 0;
        int n = S.length();
        int start = 0;
        for(int i=0;i<n;i++){
            if(i-start+1>K){
                m[S[start]] -= 1;
                start ++;
            }
            if(m[S[i]]!=0){
                while(start<i&&m[S[i]]!=0){
                    m[S[start]] -= 1;
                    start ++;
                }
                m[S[i]] += 1;
            }
            else{
                if(i-start+1==K){
                    cnt ++;
                    m[S[start]] -= 1;
                    start += 1;
                }
                m[S[i]] += 1;
            }
        }
        return cnt;
    }
};
