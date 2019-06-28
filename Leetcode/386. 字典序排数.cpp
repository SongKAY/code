class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> m;
        for(int i=1;i<=n;i++)
            m.push_back(to_string(i));
        sort(m.begin(),m.end());
        vector<int> temp;
        for(auto a:m){
            temp.push_back(stoi(a));
        }
        return temp;
    }
};
