class Solution {
public:
    int strangePrinter(string s) {
        if(s.length()==0)
            return 0;
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        for(int i = n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j] = dp[i+1][j]+1;
                for(int k=i+1;k<j;k++){
                    if(s[i]==s[k]){
                        dp[i][j] = min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
                    }
                }
                if(s[i]==s[j])
                    dp[i][j] = min(dp[i][j],dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};
