class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,1);
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                int t = max(j*(i-j),j*dp[i-j]);
                dp[i] = max(t,dp[i]);
            }
        }
        return dp[n];
    }
};
