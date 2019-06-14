class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int mincnt = INT_MAX;
            for(int j=1;j*j<=i;j++){
                mincnt = min(mincnt,dp[i-j*j]);
            }
            dp[i] = mincnt + 1;
        }
        return dp[n];
    }
};
