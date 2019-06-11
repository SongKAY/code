class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        set<string> temp(wordDict.begin(),wordDict.end());
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&temp.count(s.substr(j,i-j))){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    } 
};
