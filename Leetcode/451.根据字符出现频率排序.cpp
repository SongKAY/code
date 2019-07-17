class Solution {
public:
    static bool cmp(pair<char,int> a,pair<char,int> b){
        if(a.second!=b.second)
            return a.second>b.second;
        return a.first<b.first;
    }
    string frequencySort(string s) {
        vector<pair<char,int>> temp;
        map<int,int> m;
        for(auto a:s){
            m[a]++;
        }
        for(auto a:s){
            temp.push_back(make_pair(a,m[a]));
        }
        sort(temp.begin(),temp.end(),cmp);
        string str;
        for(auto a:temp)
            str+=a.first;
        return str;
    }
};
