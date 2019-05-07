class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        map<char,int> m;
        vector<int> result;
        int i = 0;
        for(char a='a';a<='z';a++){
            m[a] = widths[i++];
        }
        int cnt = 1;
        int left = 0;
        for(int j=0;j<S.length();j++){
            if(left + m[S[j]]>100){
                cnt ++;
                left = m[S[j]];
            }
            else{
                left += m[S[j]];
            }
        }
        result.push_back(cnt);
        result.push_back(left);
        return result;
    }
};
