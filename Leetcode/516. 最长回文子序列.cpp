class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if(n==0)
            return 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int result = 1;
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        for(int j=n-1;j>=0;j--){
            for(int i=j+1;i<n;i++){
                if(s[i]==s[j])
                    dp[j][i] = max(dp[j][i],dp[j+1][i-1]+2);
                else
                    dp[j][i] = max(dp[j+1][i],dp[j][i-1]);
            }
        }
        return dp[0][n-1];
    }
};
