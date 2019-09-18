class Solution {
public:
    int integerBreak(int n) {
        if(n<=3)
            return n-1;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i=4;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i] = max(dp[i],max((i-j)*dp[j],(i-j)*j));
            }
        }
        return dp[n];
    }
};
