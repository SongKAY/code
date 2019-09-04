

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,vector<string>> m;
        return helper(s, wordDict, m);
    }
    vector<string> helper(string s,vector<string>& wordDict, unordered_map<string,vector<string>>& m){
        if(m.count(s)) 
            return m[s];
        if(s=="")
            return {""};
        vector<string> res;
        for(auto word:wordDict){
            if(s.substr(0,word.size())!=word)
                continue;
            vector<string> temp = helper(s.substr(word.size()),wordDict,m);
            for(auto str:temp){
                res.push_back(word+ (str.empty()?"":" ") + str);
            }
        }
        return m[s] = res;
    }
};
