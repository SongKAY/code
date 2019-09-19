class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length()!=B.length())
            return false;
        int cnt = 0;
        int pre;
        map<char,int> m;
        int flag = 0;
        for(int i=0;i<A.length();i++){
            m[A[i]] ++;
            if(m[A[i]]>=2)
                flag = 1;
            if(A[i]!=B[i]){
                cnt ++;
                if(cnt>2)
                    return false;
                if(cnt==1)
                    pre = i;
                if(cnt==2){
                    if(A[pre]!=B[i]||B[pre]!=A[i])
                        return false;
                }
            }
        }
        if(cnt==0&&!flag)
            return false;
        return true;
    }
};
