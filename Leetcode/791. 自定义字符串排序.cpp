class Solution {
public:
    static bool cmp(pair<char,int> a,pair<char,int> b){
        return a.second<b.second;
    }
    string customSortString(string S, string T) {
        map<char,int> index;
        int cnt = 0;
        for(int i=0;i<S.length();i++){
            if(index[S[i]]==0){
                index[S[i]] = ++cnt;
            }
        }
        for(char a = 'a';a<='z';a++){
            if(index[a]==0){
                index[a] = ++cnt;
            }
        }
        vector<pair<char,int>> v;
        for(int i=0;i<T.length();i++){
            v.push_back(make_pair(T[i],index[T[i]]));
        }
        sort(v.begin(),v.end(),cmp);
        string str;
        for(int i=0;i<v.size();i++){
            str += v[i].first;
        }
        return str;
    }
};
