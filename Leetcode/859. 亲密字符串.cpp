class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length()!=B.length())
            return false;
        int cnt = 0;
        vector<vector<int>> temp;
        for(int i=0;i<A.length();i++){
            if(A[i]!=B[i]){
                cnt ++;
                temp.push_back({A[i],B[i]});
            }
            if(cnt>2)
                return false;
        }
        if(cnt==1)
            return false;
        if(cnt==0){
            map<char,int> m;
            for(int i=0;i<A[i];i++){
                m[A[i]]++;
                if(m[A[i]]>=2)
                    return true;
            }
            return false;
        }
        if((temp[0][0]==temp[1][1]&&temp[0][1]==temp[1][0]))
            return true;
        return false;
    }
};
