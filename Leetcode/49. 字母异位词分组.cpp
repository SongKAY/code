class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        vector<string> key;
        for(auto s:strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            if(m[temp].empty())
                key.push_back(temp);
            m[temp].push_back(s);
        }
        vector<vector<string>> result;
        for(auto s:key){
            result.push_back(m[s]);
        }
        return result;
    }
};
