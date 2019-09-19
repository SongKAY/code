class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length()+1;
        int m = p.length()+1;
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = 1;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                if(i>0&&(s[i-1]==p[j-1]||p[j-1]=='.'))
                    dp[i][j] = dp[i-1][j-1];
                if(p[j-1]=='*'){
                    if(i==0||(p[j-2]!=s[i-1]&&p[j-2]!='.'))
                        dp[i][j] = dp[i][j-2];
                    else
                        dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
