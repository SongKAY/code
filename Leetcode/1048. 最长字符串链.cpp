class Solution {
public:
    static bool cmp(string a,string b){
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        if(words.empty())
            return 0;
        int n = words.size();
        unordered_map<string,int> cnt;
        sort(words.begin(),words.end(),cmp);
        int result = 1;
        for(auto word:words){
            int num = 1;
            for(int i=0;i<word.length();i++){
                string s = word;
                s.erase(i,1);
                if(cnt.count(s))
                    num = max(num,cnt[s]+1);
            }
            cnt[word] = num;
            result = max(num,result);
        }
        return result;
    }
};
